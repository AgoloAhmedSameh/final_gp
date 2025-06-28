import subprocess
import black
import re
import helpers
from collections import deque

def SwitchHandler(code):

    # print(code)

    transformed_lines = []

    switch_statement = False
    inside_case_statement = False
    damaged_case_block = False

    stack = deque()
    for line in code.split('\n'):
        current_indentation = (len(line) - len(line.lstrip())) * ' '


        query_line = helpers.ClearStrings(line.strip())

        prev_query_line = None
        if len(transformed_lines) > 0:
            prev_query_line = helpers.ClearStrings(transformed_lines[-1].strip())

        if 'switch' in query_line and not switch_statement:
            switch_statement = True
            transformed_lines.append(line)
            continue
        elif switch_statement and not inside_case_statement and ('case' == query_line[:4] or 'default' == query_line[:7]):
            inside_case_statement = True
        elif switch_statement and inside_case_statement and (prev_query_line[:4] == 'case' or prev_query_line[:7] == 'default') and query_line != '{':
            damaged_case_block = True
            transformed_lines.append(current_indentation + '{')
            stack.append(query_line)
        elif switch_statement and inside_case_statement and ('case' == query_line[:4] or 'default' == query_line[:7]):
            if damaged_case_block:
                transformed_lines.append(current_indentation + '}')
                stack.pop()
            damaged_case_block = False
        elif switch_statement and'{' == query_line:
            stack.append(query_line)
        elif switch_statement and '}' == query_line:
            stack.pop()
        if switch_statement and damaged_case_block and len(stack) == 1:
            transformed_lines.append(current_indentation + '}')
            stack.pop()
        if switch_statement and len(stack) == 0:
            switch_statement = False
            damaged_case_block = False
        transformed_lines.append(line)
    return '\n'.join(transformed_lines)

# def SwitchHandler(code):
#     def wrap_case_statements(match):
#         case_label = match.group(1)  # "case X:" or "default:"
#         case_body = match.group(2).strip()  # Body of the case

#         # Ensure braces are added only if not already present
#         if case_body.startswith("{") and case_body.endswith("}"):
#             return match.group(0)  # Return as-is
#         return f"{case_label}\n{{\n    {case_body}\n}}"

#     # Regex to match case statements
#     case_pattern = r"(case\s+\w+:|default:)([^\{;]*;)"
#     formatted_code = re.sub(case_pattern, wrap_case_statements, code)
#     return formatted_code

# def SwitchHandler(code):
#     def wrap_case_statements(match):
#         case_label = match.group(1).strip()  # Case label (e.g., "case int x if (x > 0):" or "default:")
#         case_body = match.group(2).strip()  # Case body

#         # Check if the body already has braces
#         if case_body.startswith("{") and case_body.endswith("}"):
#             return match.group(0)  # Return as-is

#         # Add braces around the body
#         indented_body = "\n".join(f"    {line}" for line in case_body.splitlines())
#         return f"{case_label}\n{{\n{indented_body}\n}}"

#     # Regex to match case patterns with bodies (including multiline)
#     case_pattern = r"(case\s+.*?:|default:)([^{}]+?)(?=\n\s*(case\s+.*?:|default:|\}))"
#     formatted_code = re.sub(case_pattern, wrap_case_statements, code, flags=re.S)
#     return formatted_code


class Formater:
    def CPP(code, clang_format_path="clang-format"):
        """
        Formats C++ code using clang-format and adds additional transformations:
        - Aligns braces vertically.
        - Ensures each statement ends with a semicolon.
        """
        # Updated clang-format style for ANSI brace style
        clang_style = (
            "{BasedOnStyle: GNU, "
            "BraceWrapping: {AfterFunction: true, AfterControlStatement: true, AfterStruct: false, AfterClass: false, AfterNamespace: false, SplitEmptyFunction: true, AfterCaseLabel: true  }, "
            "IndentWidth: 4, ColumnLimit: 0, AllowShortBlocksOnASingleLine: false, AllowShortFunctionsOnASingleLine: false}"
        )

        # Step 1: Run clang-format
        process = subprocess.Popen(
            [clang_format_path, f"-style={clang_style}"],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
        )
        stdout, stderr = process.communicate(input=code.encode())
        if stderr:
            raise RuntimeError(f"ClangFormat error: {stderr.decode()}")

        formatted_code = stdout.decode()

        # Step 2: Post-process to wrap case statements with braces
        formatted_code = SwitchHandler(formatted_code)
        # Optionally, write formatted code to a file
        with open("formatted_CPP_code.cpp", "w") as file:
            file.write(formatted_code)

        return formatted_code
    
    def Java(code, formatter_path='google-java-format-1.25.2-all-deps.jar'):
        """
        Formats Java code to ensure vertical curly braces and saves it to a new file.

        Args:
            input_file (str): Path to the original Java file.
            output_file (str): Path where the formatted file will be saved.
            formatter_path (str): Path to google-java-format jar.
        """
        # Step 1: Run google-java-format
        

        process = subprocess.Popen(
            ["java", "-jar", formatter_path, "-"],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
        )
        stdout, stderr = process.communicate(input=code.encode())
        if stderr:
            raise RuntimeError(f"Formatting error: {stderr.decode()}")

        formatted_code = stdout.decode()

        # Step 2: Apply custom transformation for vertical curly brackets
        lines = formatted_code.split("\n")
        transformed_lines = []

        for line in lines:
            query_string = line.strip()
            
            if len(query_string) == 0:
                continue
            current_indentation = (len(line) - len(line.lstrip())) * ' '

            if (query_string[0] == '}' and query_string[-1] == '{'):
                transformed_lines.append(current_indentation + '}')
                transformed_lines.append(current_indentation + line.strip()[1:-1])
                transformed_lines.append(current_indentation + '{')
            elif (query_string[-1] == '{'):
                transformed_lines.append(line.rstrip()[:-1])
                transformed_lines.append(current_indentation + '{')
            elif(query_string[0] == '}'):
                transformed_lines.append(current_indentation + '}')
                transformed_lines.append(current_indentation + query_string[1:])
            else:
                transformed_lines.append(line)
        

        
        # Step 3: Save to the output file
        with open("formatted_Java_code.java", "w") as file:
            formatted_code = '\n'.join(transformed_lines)
            formatted_code = SwitchHandler(formatted_code)
            file.write(formatted_code)

        return formatted_code


    def JavaScript(code):
        """
        Formats JavaScript code using Prettier.
        """
        prettier_path = r"C:\Users\abdel\AppData\Roaming\npm\prettier.cmd"

        process = subprocess.Popen(
            [prettier_path, "--parser", "babel", "--bracket-same-line", "false"],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
        )
        
        stdout, stderr = process.communicate(input=code.encode())

        if stderr:
            raise RuntimeError(f"Formatting error: {stderr.decode()}")

        formatted_code = stdout.decode()

        lines = formatted_code.split("\n")
        transformed_lines = []

        for line in lines:
            query_string = line.strip()
            
            if len(query_string) == 0:
                continue
            current_indentation = (len(line) - len(line.lstrip())) * ' '

            if (query_string[0] == '}' and query_string[-1] == '{'):
                transformed_lines.append(current_indentation + '}')
                transformed_lines.append(current_indentation + line.strip()[1:-1])
                transformed_lines.append(current_indentation + '{')
            elif (query_string[-1] == '{'):
                transformed_lines.append(line.rstrip()[:-1])
                transformed_lines.append(current_indentation + '{')
            elif(query_string[0] == '}'):
                transformed_lines.append(current_indentation + '}')
                transformed_lines.append(current_indentation + query_string[1:])
            else:
                transformed_lines.append(line)
        
        with open("formatted_JavaScript_code.js", "w") as file:
            formatted_code = '\n'.join(transformed_lines)
            formatted_code = SwitchHandler(formatted_code)
            file.write(formatted_code)

        return formatted_code

    def Python(code, line_length=999):
        """
        Formats a Python code string using Black with custom options.

        - line_length: Sets the maximum line length.
        - Avoids splitting lines based on trailing commas.
        """
        try:
            # Configure Black formatting options
            mode = black.Mode(line_length=line_length,magic_trailing_comma=False)
            formatted_code = black.format_str(code, mode=mode)


            with open("formated_Python_code.py", "w") as file:
                file.write(formatted_code)

            return formatted_code
        except black.NothingChanged:
            
            with open("formated_Python_code.py", "w") as file:
                file.write(code)

            return code
        

# all of the following was for testing!
    
# with open("CPPExamples/cpp_example1.cpp", 'r') as f: 
#     code = f.read()
#     print(code)
#     print(40 * "*")
#     print(Formater.CPP(code))

# with open("JavaExamples/java_example.java", 'r') as f: print(Formater.Java(f.read()))

# javaScriptCode = """
# class Animal {
#   constructor(name, sound) {
#     this.name = name;
#     this.sound = sound;
#   }

#   makeSound() {
#     console.log(`${this.name} says ${this.sound}`);
#   }
# }

# const dog = new Animal("Dog", "Woof");
# dog.makeSound(); // Output: Dog says Woof
# """

# print(Formater.JavaScript(javaScriptCode))


