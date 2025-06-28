#java setup
import subprocess
import platform
import os

# Check if we're on Windows and handle Java setup accordingly
if platform.system() == "Windows":
    # On Windows, we'll assume Java is installed or provide instructions
    # You can install Java manually or use a package manager like Chocolatey
    try:
        # Check if Java is available
        subprocess.run(["java", "-version"], capture_output=True, check=True)
    except (subprocess.CalledProcessError, FileNotFoundError):
        print("Warning: Java not found. Please install Java Development Kit (JDK) manually.")
        print("You can download it from: https://adoptium.net/ or use Chocolatey: choco install openjdk")
else:
    # Linux/Unix systems
    try:
        # Update the package list
        subprocess.run(["apt-get", "update"], check=True)
        # Install default JDK
        subprocess.run(["apt-get", "install", "-y", "default-jdk"], check=True)
    except (subprocess.CalledProcessError, FileNotFoundError):
        print("Warning: apt-get not available. Please install Java manually.")

import subprocess
import os
import tempfile
import re
import io
import sys
import ast
import subprocess
# --- Helper functions ---

def run_cpp_code(cpp_code):
    with tempfile.TemporaryDirectory() as temp_dir:
        cpp_file = os.path.join(temp_dir, "code.cpp")
        exe_file = os.path.join(temp_dir, "code.exe")

        with open(cpp_file, "w") as f:
            f.write(cpp_code)

        try:
            compile_result = subprocess.run(
                ["g++", cpp_file, "-o", exe_file],
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True
            )

            if compile_result.returncode != 0:
                return f"Compilation failed:\n{compile_result.stderr}"

            run_result = subprocess.run(
                [exe_file],
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True
            )

            if run_result.returncode != 0:
                return f"Execution failed:\n{run_result.stderr}"

            return run_result.stdout

        except FileNotFoundError:
            return "Error: g++ compiler is not installed or not in PATH."


def cpp_rate(code, list_of_asserts):
    totalTestCases = len(list_of_asserts)
    success_rate = 0
    faild_asserts=[]
    for i in list_of_asserts:
        print(i)
        test_case = f'''
        #include <iostream>
        #include <cassert>
        #include <iostream>
        #include <filesystem>   // C++17

        {code}

        int main() {{
            try {{
                {i}
            }} catch (const std::exception& e) {{
                std::cerr << "Assertion failed: " << e.what() << '\\n';
            }} catch (...) {{
                std::cerr << "Unknown error occurred" << '\\n';
            }}
            return 0;
        }}
        '''
        res = run_cpp_code(test_case)
        print(res)

        if "failed" in res or "Error" in res:
            faild_asserts.append(i)
            continue
        else:
            success_rate += 1

    success_rate = success_rate / totalTestCases
    if success_rate < 0.1:
        success_rate = 0.0

    return success_rate,faild_asserts


def run_js_code(js_code):
    with tempfile.TemporaryDirectory() as temp_dir:
        js_file = os.path.join(temp_dir, "script.js")

        with open(js_file, "w") as f:
            f.write(js_code)

        try:
            run_result = subprocess.run(
                ["node", js_file],
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True,
                check=True
            )

            return run_result.stdout + "\n" + run_result.stderr if run_result.stderr else run_result.stdout
        except subprocess.CalledProcessError as e:
            return f"Execution failed with error code {e.returncode}:\n{e.stderr}\n{e.stdout}"
        except FileNotFoundError:
            return "Error: node.js is not installed or not in PATH."
        except Exception as e:
            return f"An unexpected error occurred: {str(e)}"


def javascript_rate(code, list_of_asserts):
    totalTestCases = len(list_of_asserts)
    success_rate = 0
    faild_asserts=[]
    for i in list_of_asserts:
        test_case = f'''
        {code}

        {i}
        '''
        res = run_js_code(test_case)
        if "failed" in res or "Error" in res:
            faild_asserts.append(i)
            continue
        else:
            success_rate += 1

    success_rate = success_rate / totalTestCases
    return success_rate,faild_asserts

def python_rate(code, list_of_asserts):
    # Redirect stdout to capture terminal content
    buffer = io.StringIO()
    original_stdout = sys.stdout
    sys.stdout = buffer
    faild_asserts=[]
    try:
        # Execute the provided code
        exec(code)

        # Initialize counters
        total_test_cases = len(list_of_asserts)
        success_rate = 0

        # Convert test case string into actual assertions
        if isinstance(list_of_asserts, str):
            try:
                list_of_asserts = ast.literal_eval(list_of_asserts)
            except (SyntaxError, ValueError):
                sys.stdout = original_stdout
                return 0.0, "Error: Test cases are not properly formatted."

        # Ensure test cases are properly structured
        if not isinstance(list_of_asserts, list):
            sys.stdout = original_stdout
            return 0.0, "Error: Test cases should be a list of assertions."

        # Evaluate each assertion
        for assertion in list_of_asserts:
            try:
                exec(assertion)  # Execute the assertion
                success_rate += 1  # Increment if successful
            except Exception as e:
                faild_asserts.append(assertion)
                print(f"Assertion failed: {e}")

        # Calculate success rate
        success_rate = success_rate / total_test_cases
    finally:
        # Reset stdout
        sys.stdout = original_stdout

    # Get the captured output
    captured_output = buffer.getvalue()

    return success_rate,faild_asserts

def run_java_code(java_code):
    with tempfile.TemporaryDirectory() as temp_dir:
        java_file = os.path.join(temp_dir, "Main.java")

        # Save Java code to a file
        with open(java_file, "w") as f:
            f.write(java_code)

        try:
            # Compile the Java code using javac
            compile_result = subprocess.run(
                ["javac", java_file],
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True
            )

            # Check for compilation errors
            if compile_result.returncode != 0:
                return f"Compilation failed:\n{compile_result.stderr}"

            # Run the compiled Java program
            class_name = "Main"  # Adjust if the class name differs
            run_result = subprocess.run(
                ["java", "-ea","-cp", temp_dir, class_name],
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True
            )
            print(run_result)
            # Check for runtime errors
            if run_result.returncode != 0:
                return f"Execution failed:\n{run_result.stderr}"

            # Return the program's output
            return run_result.stdout

        except FileNotFoundError as e:
            return f"Error: javac or java is not installed or not in PATH. {e}"

        except Exception as e:
            return f"An unexpected error occurred: {e}"


def java_rate(code, list_of_asserts,desc,language):
    totalTestCases = len(list_of_asserts)
    success_rate = 0
    num_of_cases=0
    faild_asserts=[]
    if totalTestCases==0:
        return 0.0, faild_asserts


    result=f"""
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.Stack;
import java.util.StringJoiner;
import java.util.TreeSet;
import java.util.function.BiFunction;
import java.util.function.Predicate;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.AbstractMap;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedHashSet;
import static java.lang.Math.PI;
import static java.lang.Math.tan;
import java.awt.geom.Point2D;
import java.math.BigInteger;
import static java.lang.Math.*;
import java.util.Arrays;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.time.DateTimeException;
import java.time.LocalDate;
import java.util.List;
import java.util.ArrayList;
import java.util.*;
import java.util.regex.*;
import java.util.Arrays;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Arrays;
import java.util.Comparator;
import java.util.stream.Collectors;
import java.util.stream.Collectors;
import java.util.stream.Collectors;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.AbstractMap.SimpleEntry;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.HashMap;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Set;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Arrays;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Arrays;
import java.util.List;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Set;
import java.util.stream.Collectors;
import java.util.List;
import java.util.Arrays;
import java.util.Stack;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.nio.charset.StandardCharsets;

    public class Main {{
        {code}

        public static void main(String[] args) {{
            // No code inside this method
            // No System.out.println
            // No function calls
            // No Statements here
            <ASSERT TOKEN>
        }}
    }}
    """
    for i in list_of_asserts:
        if "assert" in i:
            if ";" not in i:
                i=i+";"
            if i[-1]==']':
                i=i[:-1]
            if i[0]=='[':
                i=i[1:]

            num_of_cases+=1
            result2=result
            result2=result2.replace("```java","")
            result2=result2.replace("```","")
            result2=result2.replace("<ASSERT TOKEN>",i)
            res = run_java_code(result2)
            if "failed" in res or "Error" in res or "Exception" in res:
                faild_asserts.append(i)
                continue
            else:
                success_rate += 1
    success_rate = success_rate / num_of_cases
    return success_rate,faild_asserts

# --- Main controller function ---

def calculate_correctness(code, asserts, language):
    try:
        if language == "cpp":
            return cpp_rate(code, asserts)
        elif language == "javascript":
            return javascript_rate(code, asserts)
        elif language == "python":
            return python_rate(code,asserts)
        elif language == "java":
            return java_rate(code,asserts,"",language)
        else:
            print(f"Unsupported language: {language}")
            return 0.0, []
    except Exception as e:
        print(f"Error in calculate_correctness: {e}")
        return 0.0, []
