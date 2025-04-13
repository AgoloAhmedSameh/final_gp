import os
import tempfile
import subprocess
import ast

def check_js_syntax(js_code):
    with tempfile.TemporaryDirectory() as temp_dir:
        js_file = os.path.join(temp_dir, "script.js")

        # Save JavaScript code to a file
        with open(js_file, "w") as f:
            f.write(js_code)

        # Check for syntax errors using Node.js
        run_result = subprocess.run(
            ["node", "--check", js_file],  # --check option for syntax checking
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            check=False  # Don't raise an exception automatically
        )

        return not(bool(run_result.stderr) ) # Return false if there's a syntax error, otherwise False

def check_java_syntax(java_code):
    with tempfile.TemporaryDirectory() as temp_dir:
        java_file = os.path.join(temp_dir, "MainClass.java")
        # Write Java code to a file
        with open(java_file, "w") as f:
            f.write(java_code)
        # Compile Java Code
        compile_result = subprocess.run(
            ["javac", java_file],  # javac is the Java compiler
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )

        return not(bool(compile_result.returncode) ) # Returns false if syntax error, False if correct
def check_cpp_syntax(cpp_code):
    # Create a temporary directory
    with tempfile.TemporaryDirectory() as temp_dir:
        cpp_file = os.path.join(temp_dir, "code.cpp")

        # Write the C++ code to a file
        with open(cpp_file, "w") as f:
            f.write(cpp_code)

        # Compile the C++ code
        compile_result = subprocess.run(
            ["g++", "-fsyntax-only", cpp_file],  # "-fsyntax-only" checks for syntax errors only
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )

        return not(bool(compile_result.returncode))  # Returns false if syntax error, False if correct
def check_python_syntax(python_code):
    try:
        ast.parse(python_code)  # Parse the code to check for syntax errors
        return True  
    except SyntaxError:
        return False 

def check_syntax(language, code):
    if language.lower() == "python":
        return check_python_syntax(code)
    elif language.lower() == "c++":
        return check_cpp_syntax(code)
    elif language.lower() == "java":
        return check_java_syntax(code)
    elif language.lower() == "javascript":
        return check_js_syntax(code)
    else:
        raise ValueError("Unsupported language. Choose from: 'python', 'c++', 'java', 'javascript'.")
  