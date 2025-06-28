import re

def extract_code_and_asserts(output: str):
    code_match = re.search(r"<OUTPUTCODE>\s*(.*?)\s*</OUTPUTCODE>", output, re.DOTALL)
    code = code_match.group(1).strip() if code_match else ""

    asserts_match = re.search(r"<OUTPUTASSERTS>\s*(.*?)\s*</OUTPUTASSERTS>", output, re.DOTALL)
    asserts = asserts_match.group(1).strip() if asserts_match else ""

    return code, asserts

import re

def extract_asserts_only(output: str):
    asserts_match = re.search(r"<OUTPUTASSERTS>\s*(.*?)\s*</OUTPUTASSERTS>", output, re.DOTALL)
    asserts = asserts_match.group(1).strip() if asserts_match else ""

    # Manually wrap the asserts in brackets
    asserts = f"[{asserts}]"

    return asserts
import re

# Function to clean and extract assertions for JavaScript
def clean_generated_asserts(generated_asserts):
    split_asserts = re.split(r'console\.assert\(', generated_asserts)[1:]

    # Prepend 'console.assert(' back to each part and remove any trailing symbols except ')'
    cleaned_asserts = []
    for s in split_asserts:
        s = s.strip()
        s = re.sub(r'[^)]*$', '', s)  # Remove any trailing characters except ')'
        cleaned_asserts.append(f'console.assert({s})')

    return cleaned_asserts

# Function to extract assert statements from C++ code
def extract_asserts(text):
    cpp_response = text.strip()
    cpp_response = re.sub(r"```[a-zA-Z]*", "", cpp_response).strip()  # Remove language markers (e.g., ```cpp)
    cpp_response = cpp_response.replace("std::vector<std::string>", "").strip()  # Convert C++ vector to Python list

    # Pattern to match assert statements
    pattern = r'assert\s*\('
    matches = [m.start() for m in re.finditer(pattern, cpp_response)]

    assert_statements = []

    for start in matches:
        balance = 0
        end = start
        while end < len(cpp_response):  # Ensure to process the cleaned text
            if cpp_response[end] == '(':
                balance += 1
            elif cpp_response[end] == ')':
                balance -= 1
                if balance == 0:
                    assert_statements.append(cpp_response[start:end + 1] + ";")  # Include semicolon if present
                    break
            end += 1

    return assert_statements

# Function to extract assert statements from Python code
def parsPy(response):
    test_cases = []
    for i in response.split("\n"):
        if "assert" in i:
            test_cases.append(i)
    return test_cases

# Function to extract assert statements from Java code
def parseJava(response):
    response = response.replace("java", "")
    # Remove any language markers
    response = re.sub(r"```[a-zA-Z]*", "", response).strip()
    test_cases = re.findall(r'\bassert\s+[^;]+;', response)
    test_cases = [a.strip() for a in test_cases]

    if len(test_cases) == 0:
        test_cases = re.findall(r'assert\s+.*?\)', response)
        for i in range(len(test_cases)):
            if test_cases[i][-1] == "]":
                test_cases[i] = test_cases[i][:-1]
            if test_cases[i][0] == "[":
                test_cases[i] = test_cases[i][1:]
            if test_cases[i][-1] != ";":
                test_cases[i] += ";"

    return test_cases

# Main function to handle responses based on the language and process assertions
def parse_llm_response(language, response, code):
    if language in code:
        code = code.replace(language, " ")

    code = code.replace("```", "")

    if language == "cpp":
        assertion_list = extract_asserts(response)
        return assertion_list, code

    if language == "python":
        assertion_list = parsPy(response)
        return assertion_list, code

    if language == "javascript":
        assertion_list = clean_generated_asserts(response)
        return assertion_list, code

    if language == "java":
        assertion_list = parseJava(response)
        return assertion_list, code
