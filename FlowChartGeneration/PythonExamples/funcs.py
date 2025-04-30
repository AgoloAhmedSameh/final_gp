import ast

def extract_functions(file_path):
    with open(file_path, "r", encoding="utf-8") as f:
        tree = ast.parse(f.read())

    functions = {}
    
    for node in ast.walk(tree):
        if isinstance(node, ast.FunctionDef):  # Find function definitions
            func_name = node.name
            func_body = ast.unparse(node)  # Convert AST back to source code
            functions[func_name] = func_body

    return functions

# Example usage
file_path = "example.py"  # Replace with your file path
functions = extract_functions(file_path)

for name, body in functions.items():
    print(f"Function: {name}\n{body}\n{'-'*40}")
