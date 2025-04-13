import re
import ast
import subprocess
from transformers import pipeline
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
            with open("Temp.java", "w") as f:
                f.write(code)
            result = subprocess.run(["javac", "Temp.java"], capture_output=True, text=True)
            return result.stderr.strip() if result.returncode != 0 else None
        except FileNotFoundError:
            return "Java validation requires JDK installed."
    
    elif language.lower() == "javascript":
        try:
            with open("temp.js", "w") as f:
                f.write(code)
            result = subprocess.run(["node", "--check", "temp.js"], capture_output=True, text=True)
            return result.stderr.strip() if result.returncode != 0 else None
        except FileNotFoundError:
            return "JavaScript validation requires Node.js installed."

    elif language == "c++":
        try:
            with open("temp.cpp", "w") as f:
                f.write(code)
            result = subprocess.run(["g++", "-fsyntax-only", "temp.cpp"], capture_output=True, text=True)
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
    response = Qwen(DEFAULT_SYSTEM_PROMPT,prompt)
    code = response.replace("<OUTPUT>", "").replace("</OUTPUT>", "").strip().split("\n")[0] 
    return code 