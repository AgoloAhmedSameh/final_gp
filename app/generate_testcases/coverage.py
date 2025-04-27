import subprocess
import os
import re
import tempfile
import xml.etree.ElementTree as ET
import traceback
import sys

# ---------------------- Setup Tools ---------------------------

def install_dependencies():
    try:
        subprocess.run(["apt-get", "update"], check=True)
        subprocess.run(["apt-get", "install", "-y", "g++"], check=True)
        subprocess.run(["apt-get", "install", "-y", "default-jdk"], check=True)
        subprocess.run(["wget", "https://repo1.maven.org/maven2/org/jacoco/jacoco/0.8.10/jacoco-0.8.10.zip"], check=True)
        subprocess.run(["unzip", "jacoco-0.8.10.zip"], check=True)
        subprocess.run(["mv", "lib/jacocoagent.jar", "."], check=True)
        subprocess.run(["mv", "lib/jacococli.jar", "."], check=True)
        subprocess.run(["curl", "-sL", "https://deb.nodesource.com/setup_14.x", "|", "sudo", "-E", "bash", "-"], shell=True, check=True)
        subprocess.run(["apt-get", "install", "-y", "nodejs"], check=True)
    except subprocess.CalledProcessError as e:
        print(f"Error installing dependencies: {e}")

# ------------------- CPP Coverage ------------------------------

def generate_cpp_assert_cases(asserts):
    cases = ""
    for i, assert_stmt in enumerate(asserts):
        cases += f"""
        case {i}:
            {assert_stmt}
            break;
        """
    return cases

def parse_gcov_file(gcov_file):
    try:
        with open(gcov_file, 'r') as f:
            lines = f.readlines()

        coverage_metrics = {
            'line': 0,
            'executed_lines': 0,
            'total_lines': 0,
            'branches': 0,
            'executed_branches': 0
        }

        start_line, end_line = None, None
        for i, line in enumerate(lines):
            if '// USER CODE START' in line:
                start_line = i + 1
            elif '// USER CODE END' in line:
                end_line = i
                break

        if start_line is None or end_line is None:
            print("Could not find code markers")
            return coverage_metrics

        for line in lines[start_line:end_line]:
            parts = line.split(':', 2)
            if len(parts) < 3:
                continue

            execution_count = parts[0].strip()
            if execution_count != '-':
                coverage_metrics['total_lines'] += 1
                if execution_count != '#####':
                    coverage_metrics['executed_lines'] += 1

            if 'branch' in line:
                coverage_metrics['branches'] += 1
                if 'taken' in line and not 'never' in line:
                    coverage_metrics['executed_branches'] += 1

        if coverage_metrics['total_lines'] > 0:
            coverage_metrics['line'] = (coverage_metrics['executed_lines'] /
                                        coverage_metrics['total_lines']) * 100

        return coverage_metrics

    except Exception as e:
        print(f"Error parsing gcov file: {str(e)}")
        return None

def cpp_coverage(code, list_of_asserts):
    with tempfile.TemporaryDirectory() as temp_dir:
        try:
            cpp_file = os.path.join(temp_dir, "main.cpp")

            cpp_template = f"""
#include <cassert>
#include <iostream>

// USER CODE START
{code}
// USER CODE END

int main(int argc, char* argv[]) {{
    if (argc != 2) return 1;
    int test_case = std::stoi(argv[1]);

    switch(test_case) {{
        {generate_cpp_assert_cases(list_of_asserts)}
    }}

    return 0;
}}
"""
            with open(cpp_file, "w") as f:
                f.write(cpp_template)

            compile_cmd = ["g++", "-O0", "-fprofile-arcs", "-ftest-coverage", "-g", cpp_file, "-o", os.path.join(temp_dir, "main")]
            subprocess.run(compile_cmd, check=True, cwd=temp_dir)

            for i, _ in enumerate(list_of_asserts):
                run_cmd = ["./main", str(i)]
                subprocess.run(run_cmd, check=True, cwd=temp_dir)

            subprocess.run(["gcov", "-b", "-c", "main.cpp"], check=True, cwd=temp_dir)

            coverage_file = os.path.join(temp_dir, "main.cpp.gcov")
            if not os.path.exists(coverage_file):
                print(f"Coverage file not found at {coverage_file}")
                return None

            return parse_gcov_file(coverage_file)

        except Exception as e:
            print(f"An error occurred: {str(e)}")
            print(traceback.format_exc())
            return None

# ------------------- Java Coverage ------------------------------

def generate_assert_cases(asserts):
    cases = ""
    for i, assert_stmt in enumerate(asserts):
        cases += f"""
                case "{i}":
                    {assert_stmt}
                    break;
        """
    return cases

def java_coverage(code, list_of_asserts):
    with tempfile.TemporaryDirectory() as temp_dir:
        try:
            java_file = os.path.join(temp_dir, "Main.java")
            java_template = f"""
            import java.util.*;

            public class Main {{
                {code}

                public static void main(String[] args) {{
                    String assertNum = args[0];
                    switch(assertNum) {{
                        {generate_assert_cases(list_of_asserts)}
                    }}
                }}
            }}
            """
            with open(java_file, "w") as f:
                f.write(java_template)

            subprocess.run(["javac", java_file], check=True)

            jacoco_agent_path = "jacocoagent.jar"
            jacoco_cli_path = "jacococli.jar"

            if not os.path.exists(jacoco_agent_path) or not os.path.exists(jacoco_cli_path):
                print("JaCoCo files not found!")
                return None

            jacoco_exec = os.path.join(temp_dir, "jacoco.exec")
            jacoco_agent = f"-javaagent:{jacoco_agent_path}=destfile={jacoco_exec}"

            for i, _ in enumerate(list_of_asserts):
                run_cmd = ["java", jacoco_agent, "-ea", "-cp", temp_dir, "Main", str(i)]
                subprocess.run(run_cmd, check=True)

            report_cmd = [
                "java", "-jar", jacoco_cli_path,
                "report", jacoco_exec,
                "--classfiles", temp_dir,
                "--sourcefiles", temp_dir,
                "--xml", os.path.join(temp_dir, "coverage.xml")
            ]
            subprocess.run(report_cmd, check=True)

            coverage_file = os.path.join(temp_dir, "coverage.xml")
            if not os.path.exists(coverage_file):
                print(f"Coverage report file not found: {coverage_file}")
                return None

            tree = ET.parse(coverage_file)
            root = tree.getroot()

            coverage_metrics = {
                'line': 0,
                'executed_lines': 0,
                'total_lines': 0,
                'branches': 0,
                'executed_branches': 0
            }

            for counter in root.findall(".//counter"):
                type = counter.get('type')
                covered = int(counter.get('covered'))
                missed = int(counter.get('missed'))
                total = covered + missed

                if type.lower() == 'line':
                    coverage_metrics['executed_lines'] = covered
                    coverage_metrics['total_lines'] = total
                    coverage_metrics['line'] = (covered / total * 100) if total > 0 else 0
                elif type.lower() == 'branch':
                    coverage_metrics['executed_branches'] = covered
                    coverage_metrics['branches'] = total

            return coverage_metrics

        except Exception as e:
            print(f"An error occurred: {str(e)}")
            print(traceback.format_exc())
            return None

# ------------------- JavaScript Coverage ------------------------------
def run_js_code(js_code, asserts_block=None):

    # Combine the JS code and assertions into one code block
    full_js_code = js_code
    if asserts_block:
        full_js_code += "\n" + asserts_block

    try:
        run_result = subprocess.run(
            ["node", "-e", full_js_code],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            check=True
        )
        return run_result.stdout + ("\n" + run_result.stderr if run_result.stderr else "")
    except subprocess.CalledProcessError as e:
        print("[run_js_code] Error during execution.")
        return f"Execution failed with error code {e.returncode}:\n{e.stderr}\n{e.stdout}"
    except FileNotFoundError:
        return "Error: node.js is not installed or not in PATH."
    except Exception as e:
        return f"An unexpected error occurred: {str(e)}"

def preprocess_js_code(js_code):
    return js_code

def add_line_coverage(js_code):
    lines = js_code.split('\n')
    new_code = []
    original_line_number = 0

    for line in lines:
        stripped_line = line.strip()
        if stripped_line and stripped_line not in ('{', '}') and 'function ' not in stripped_line:
            original_line_number += 1
            new_code.append(f"console.log('COVERAGE_LINE {original_line_number}');")
        new_code.append(line)

    return '\n'.join(new_code)

def js_coverage(code, asserts_block):
    code = preprocess_js_code(code)
    code_with_coverage = add_line_coverage(code)
    output = run_js_code(code_with_coverage, asserts_block)

    covered_lines = set()

    for match in re.finditer(r"COVERAGE_LINE (\d+)", output):
        line_number = int(match.group(1))
        covered_lines.add(line_number)

    executable_lines = [
        line for line in code.split('\n')
        if line.strip() and line.strip() not in ('{', '}') and 'function ' not in line
    ]
    total_lines = len(executable_lines)

    covered_lines_count = len(covered_lines)
    coverage_percentage = (covered_lines_count / total_lines) * 100 if total_lines > 0 else 0

    return {
        "coverage_percentage": round(coverage_percentage, 2),
        "covered_lines_count": covered_lines_count,
        "total_lines": total_lines
    }

# ------------------- Main Function ------------------------------

##-----------PYTHON COV--------------------###

def trace_lines(frame, event, arg):
    """Track executed lines inside <string> (code input)."""
    if event == "line" and frame.f_code.co_filename == "<string>":
        if frame.f_lineno in function_lines:
            executed_lines.add(frame.f_lineno)
    return trace_lines

def py_coverage(code: str, assertions: list) -> dict:
    """
    Calculate test coverage for a given function with weighted assertions.

    :param code: Python function as a string.
    :param assertions: List of assertion statements as strings.
    :return: Dictionary containing coverage percentage, executed lines, total lines, and executed line indexes.
    """
    global executed_lines, function_lines

    # Extract function lines excluding empty or comment lines
    function_lines = [
        i + 1 for i, line in enumerate(code.strip().split("\n"))
        if line.strip() and not line.strip().startswith("#")
    ]

    total_lines = len(function_lines)
    total_assertions = len(assertions)
    if total_assertions == 0:
        return {
            "coverage": 0.0,
            "executed_lines": [],
            "total_lines": total_lines,
            "executed_line_indexes": []
        }

    successful_assertions = 0
    combined_executed_lines = set()

    # Process each assertion separately
    for assertion in assertions:
        try:
            executed_lines = set()  # Reset for each assertion
            # Combine function code with single assertion
            full_code = code.strip() + "\n" + assertion

            namespace = {}
            sys.settrace(trace_lines)  # Start tracing
            exec(full_code, namespace)  # Run function with single assertion
            sys.settrace(None)  # Stop tracing
            # If assertion passed, update metrics
            successful_assertions += 1
            combined_executed_lines.update(executed_lines)

        except AssertionError:
            # If assertion failed, its weight will be 0
            continue
        except Exception as e:
            # Handle other exceptions
            # print(full_code)
            # print(f"Error executing assertion: {assertion}")
            # print(f"Error: {str(e)}")
            continue

    # Calculate weighted coverage
    covered_lines = len(combined_executed_lines)

    # Calculate coverage percentage with weights
    # Each assertion contributes equally to the final coverage
    coverage_percentage = round(
        (covered_lines / total_lines) * (successful_assertions / total_assertions) * 100, 2
    ) if total_lines > 0 and total_assertions > 0 else 0.0

    return {
        "coverage": coverage_percentage,
        "executed_lines": sorted(combined_executed_lines),
        "total_lines": total_lines,
        "executed_line_indexes": sorted(combined_executed_lines)
    }




##-------------------END Coverage------------------------------

def calculate_coverage(code, asserts, language):
    if language == "cpp":
        code_cpp = code.replace("```", " ")
        try:
            result = cpp_coverage(code_cpp, asserts)
            return result['line']

        except Exception as e:
            print(f"Error processing cpp: {e}")
            return 0
    elif language == "java":
        dic = java_coverage(code, asserts)
        return dic['line']

    elif language == "javascript":
        dic=js_coverage(code, asserts)
        return dic["coverage_percentage"]
    elif language == "python" :
        dic= py_coverage(code , asserts )
        return dic["coverage"]
    else:
        print(f"Unsupported language: {language}")
        return 0
