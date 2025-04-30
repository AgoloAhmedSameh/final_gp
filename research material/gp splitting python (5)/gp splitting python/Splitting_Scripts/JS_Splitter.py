#pip install esprima

import esprima
from typing import List, Tuple, Optional, Dict
from dataclasses import dataclass

@dataclass
class JavaFunctionWrapperNode:
    """Represents a JavaScript function with its properties."""
    name: str
    body: str
    calls: List[Tuple[str, int]] = None 
    class_name: Optional[str] = None
    params: List[str] = None
    docstring: Optional[str] = None
    is_override: bool = False

    def __post_init__(self):
        self.params = self.params or []
        self.calls = self.calls or []

    @property
    def hash(self) -> str:
        """Generates the hash for the function itself."""
        class_name = self.class_name or 'None'
        return f"{self.name}|{len(self.params)}|{class_name}"

def get_call_hash(call: Tuple[str, int]) -> str:
    """Generates the hash for a function call."""
    func_name, arg_count = call
    if '.' in func_name:
        class_part, method_part = func_name.rsplit('.', 1)
        return f"{method_part}|{arg_count}|{class_part}"  # Lowercase class name
    else:
        return f"{func_name}|{arg_count}|None"

built_ins = {
    'console.log', 'alert', 'setTimeout', 'setInterval', 'JSON.stringify', 'Math.abs',
    'Object.keys', 'Array.prototype.map', 'String.prototype.includes', 'super'
}

def extract_calls(node, current_func_name, class_name=None, super_class=None) -> List[Tuple[str, int]]:  
    """Extract function calls, including calls to superclass methods."""
    calls = set()

    def visit_node(n):
        if n.type == "CallExpression":
            callee = n.callee

            if callee.type == "Identifier":
                func_name = callee.name
                if func_name and func_name != current_func_name and func_name not in built_ins:
                    calls.add((func_name, len(n.arguments)))

            elif callee.type == "MemberExpression":
                object_part = callee.object
                property_part = callee.property

              
                if object_part.type == "Super":
                    object_name = super_class if super_class else "super"
                elif object_part.type == "ThisExpression":
                    object_name = class_name if class_name else "this"
                elif object_part.type == "Identifier":
                    object_name = object_part.name 
                else:
                    object_name = "unknown"

                method_name = property_part.name if property_part.type == "Identifier" else "unknown"
                full_name = f"{object_name}.{method_name}"

                if full_name not in built_ins and full_name != current_func_name:
                    calls.add((full_name, len(n.arguments)))

        for key, value in vars(n).items():
            if isinstance(value, list):
                for item in value:
                    if hasattr(item, 'type'):
                        visit_node(item)
            elif hasattr(value, 'type'):
                visit_node(value)

    visit_node(node)
    return [get_call_hash(call) for call in calls]

def extract_functions(js_code):
    """Extracts function declarations, methods, and arrow functions from JavaScript code."""
    ast = esprima.parseScript(js_code, tolerant=True, loc=True)
    functions = []
    class_methods: Dict[str, List[str]] = {}

    def process_function(node, func_name, class_name=None, super_class=None):
        params = [param.name for param in node.params] if node.params else []
        body_start = node.loc.start.line - 1
        body_end = node.loc.end.line
        func_body = "\n".join(js_code.splitlines()[body_start:body_end])
        calls = extract_calls(node.body, func_name, class_name=class_name, super_class=super_class)

        function_node = JavaFunctionWrapperNode(
            name=func_name,
            body=func_body,
            calls=calls,
            class_name=class_name,
            params=params
        )
        functions.append(function_node)

    for node in ast.body:
        if node.type == "FunctionDeclaration":
            process_function(node, node.id.name)

        elif node.type == "VariableDeclaration":
            for decl in node.declarations:
                if decl.init and decl.init.type in ["FunctionExpression", "ArrowFunctionExpression"]:
                    process_function(decl.init, decl.id.name)

        elif node.type == "ClassDeclaration":
            class_name = node.id.name
            super_class = node.superClass.name if (node.superClass and node.superClass.type == "Identifier") else None
            class_methods[class_name] = []

            for method in node.body.body:
                if method.type == "MethodDefinition" and method.key.type == "Identifier":
                    process_function(method.value, method.key.name, class_name=class_name, super_class=super_class)

    return functions

js_code = """
class Calculator {
    add(a, b) {
        return a + b;
    }

    multiply(x, y) {
        return this.add(x, y) * 2;
    }
}

function subtract(a, b) {
    return a - b;
}

const divide = (a, b) => {
    return a / b;
};

function main() {
    let calc = new Calculator();
    let result = calc.multiply(2, 3);
    console.log(result);
    return divide(result, 2);
}
"""

# Extract functions
functions = extract_functions(js_code)

# Print extracted functions with hashes
for func in functions:
    print(f"Function Name: {func.name}")
    print(f"Class Name: {func.class_name}")
    print(f"Parameters: {func.params}")
    print(f"Function Hash: {func.hash}")
    print(f"Calls: {func.calls}")
    print(f"Body:\n{func.body}")
    print("-" * 50)