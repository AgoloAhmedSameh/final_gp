import re
import ast
import subprocess
import tempfile
import os
from app.LLM.prompts import get_prompt_for_syntax_fix , DEFAULT_SYSTEM_PROMPT
from app.LLM.qween import Qwen

def detect_syntax_error(code, language):
    """
    Detects syntax errors in Python, Java, JavaScript, and C++.
    Returns the error message if found, else None.
    """
    language = language.lower()
    
    if language == "python":
        try:
            ast.parse(code)
            return None  # No syntax error
        except SyntaxError as e:
            return f"Syntax Error on line {e.lineno}: {e.msg}"
    
    elif language == "java":
        try:
            with tempfile.TemporaryDirectory() as temp_dir:
                java_file = os.path.join(temp_dir, "Temp.java")
                with open(java_file, "w") as f:
                    f.write(code)
                result = subprocess.run(["javac", java_file], capture_output=True, text=True)
                return result.stderr.strip() if result.returncode != 0 else None
        except FileNotFoundError:
            return "Java validation requires JDK installed."
    
    elif language.lower() == "javascript":
        try:
            with tempfile.TemporaryDirectory() as temp_dir:
                js_file = os.path.join(temp_dir, "temp.js")
                with open(js_file, "w") as f:
                    f.write(code)
                result = subprocess.run(["node", "--check", js_file], capture_output=True, text=True)
                return result.stderr.strip() if result.returncode != 0 else None
        except FileNotFoundError:
            return "JavaScript validation requires Node.js installed."

    elif language == "c++":
        try:
            with tempfile.TemporaryDirectory() as temp_dir:
                cpp_file = os.path.join(temp_dir, "temp.cpp")
                with open(cpp_file, "w") as f:
                    f.write(code)
                result = subprocess.run(["g++", "-fsyntax-only", cpp_file], capture_output=True, text=True)
                return result.stderr.strip() if result.returncode != 0 else None
        except FileNotFoundError:
            return "C++ validation requires g++ installed."
    
    return "Unsupported language."


def fix_syntax_error(code, language):
    """
    Detects and fixes syntax errors using LLaMA.
    """
    error_message = detect_syntax_error(code, language)
    
    if not error_message:
        return "No syntax errors detected."
    
    prompt = get_prompt_for_syntax_fix(code, error_message, language)
    response = Qwen(DEFAULT_SYSTEM_PROMPT, prompt)
    code = response.replace("<OUTPUT>", "").replace("</OUTPUT>", "").strip().split("\n")[0] 
    return code 