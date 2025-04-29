import clang.cindex
from typing import List, Dict, Tuple, Optional
from dataclasses import dataclass


@dataclass
class CppFunctionWrapperNode:
    """Represents a C++ function/method with its properties."""
    name: str
    body: str
    calls: List[Tuple[str, int, str, List[str]]] = None  # (function_name, arg_count, class_name, param_types)
    class_name: Optional[str] = None
    params: List[str] = None
    return_type: Optional[str] = None
    is_override: bool = False
    overloaded_variants: List['CppFunctionWrapperNode'] = None
    signature: str = None
    is_super: bool = False
    docstring: Optional[str] = None
    hashing: Tuple[str, int, str, List[str]] = None  # New attribute for unique function identification
    args :List[str]=None
    def __post_init__(self):
        self.params = self.params or []
        self.calls = self.calls or []
        self.overloaded_variants = self.overloaded_variants or []

        # Generate function signature if not explicitly set
        if not self.signature and self.class_name and self.name:
            param_types = [p.split()[0] for p in self.params if ' ' in p]  # Extract type from 'type name'
            self.signature = f"{self.class_name}::{self.name}({', '.join(param_types)})"

        # Generate the hashing identifier
        param_types = [p.split()[0] for p in self.params if ' ' in p]  # Extract types
        self.hashing = (self.name, len(self.params), self.class_name or "default", param_types)
        self.args= param_types
def extract_body(node: clang.cindex.Cursor, source_code: str) -> str:
    """Extracts the method body as a string from the given source code."""
    extent = node.extent
    lines = source_code.splitlines()
    return '\n'.join(lines[extent.start.line - 1:extent.end.line])

def extract_calls(node: clang.cindex.Cursor, current_func_name: str) -> List[Tuple[str, int, str, List[str]]]:
    """Extract method calls, excluding built-ins and standard library functions."""
    calls = []
    
    for child in node.walk_preorder():
        if child.kind == clang.cindex.CursorKind.CALL_EXPR:
            called_func = child.referenced
            if not called_func:
                continue
            
            called_func_name = child.spelling
            if not called_func_name or called_func_name.startswith("operator"):  # Ignore built-in operators
                continue

            # Get the argument count and data types
            arg_count = len(list(child.get_arguments()))
            param_types = [arg.type.spelling for arg in child.get_arguments()]

            # Determine class name (if available)
            called_class = called_func.semantic_parent.spelling if called_func.semantic_parent else "No_class"
            
            # Check if function is from a system header (indicating it's a built-in)
            if called_func.location.file is None or "iostream" in str(called_func.location.file):
                continue  # Ignore system headers (e.g., standard library functions)
            
            calls.append((called_func_name, arg_count,called_class,  param_types))
    
    return calls


def create_function_wrapper(node: clang.cindex.Cursor, class_name: Optional[str], source_code: str) -> CppFunctionWrapperNode:
    """Create a function wrapper for a C++ method."""
    params = [f"{param.type.spelling} {param.spelling}" for param in node.get_arguments()]
    return_type = node.result_type.spelling
    body = extract_body(node, source_code)
    calls = extract_calls(node, node.spelling)

    # Extract just the type part from each parameter string
    param_types = [p.split()[0] for p in params if ' ' in p]
    signature = f"{class_name}::{node.spelling}({', '.join(param_types)})" if class_name else f"{node.spelling}({', '.join(params)})"
    
    # Create the unique hashing identifier for the function node
    hashing = (node.spelling, len(params), class_name or "default", param_types)

    return CppFunctionWrapperNode(
        name=node.spelling,
        body=body,
        calls=calls,
        class_name=class_name or "No_Class",
        params=params,
        return_type=return_type,
        is_override=False,
        signature=signature,
        hashing=hashing
    )


def analyze_cpp_code_from_string(source_code: str) -> List[CppFunctionWrapperNode]:
    """Analyze C++ source code and extract method information."""
    index = clang.cindex.Index.create()
    translation_unit = index.parse('temp.cpp', args=['-std=c++17'], unsaved_files=[('temp.cpp', source_code)])
    if not translation_unit:
        print("Error: Failed to parse the code.")
        return []
    function_nodes = []
    class_methods: Dict[str, List[CppFunctionWrapperNode]] = {}
    function_signatures = {}
    def visit(node, class_name=None):
        """Recursively visit AST nodes."""
        if node.location.file and node.location.file.name != 'temp.cpp':
            return  # Ignore system headers
        if node.kind in {clang.cindex.CursorKind.CLASS_DECL, clang.cindex.CursorKind.STRUCT_DECL}:
            class_name = node.spelling
            class_methods[class_name] = []
        elif node.kind in {clang.cindex.CursorKind.CXX_METHOD, clang.cindex.CursorKind.FUNCTION_DECL}:
            function_node = create_function_wrapper(node, class_name, source_code)
            if class_name:
                class_methods[class_name].append(function_node)
            else:
                function_nodes.append(function_node)
            func_key = f"{class_name}::{function_node.name}" if class_name else function_node.name
            if func_key in function_signatures:
                for existing_func in function_signatures[func_key]:
                    existing_func.overloaded_variants.append(function_node)
                    function_node.overloaded_variants.append(existing_func)
                function_signatures[func_key].append(function_node)
            else:
                function_signatures[func_key] = [function_node]
            if class_name and node.is_virtual_method():
                parent = node.semantic_parent
                if parent and parent.kind == clang.cindex.CursorKind.CLASS_DECL:
                    function_node.is_override = True
        for child in node.get_children():
            visit(child, class_name)
    visit(translation_unit.cursor)
    for methods in class_methods.values():
        function_nodes.extend(methods)
    print(f"Extracted {len(function_nodes)} functions.")
    return function_nodes

# Example usage:
if __name__ == "__main__":
    cpp_source_code = """



#include <iostream>
using namespace std;

// ========================= Function Overloading =========================
class MathOperations {
public:
    // Overloaded functions with different parameter lists
    int sum(int a, int b) {
        return a + b;
    }

    double sum(double a, double b) {
        return a + b;
    }

    int sum(int a, int b, int c) {
        return sum(a,b)+c;
    }
};
class Advanced : MathOperations{
public :
 double sum(double a, double b) {
        MathOperations().sum(a,b);
    }



'''


    """
#     functions = analyze_cpp_code_from_string(cpp_source_code)
#     for func in functions:
#         print(f"Class: {func.class_name if func.class_name else 'Global'}")
#         print(f"  Method: {func.name}")
#         print(f"  Signature: {func.signature}")
#         print(f"  Is Override: {func.is_override}")
#         print(f" Hashing :{func.hashing}")
#         print(f"  Overloaded Variants: {len(func.overloaded_variants)}")
#         print(f"  Parameters: {func.params}")
#         print(f"  Calls: {func.calls}")
#         print(f"  Body:\n{func.body}\n")

# def replace_function_names_with_hash(nodes: List[CppFunctionWrapperNode]) -> List[CppFunctionWrapperNode]:
#     """Replaces function names and calls in function bodies with hashed identifiers."""
    
#     hash_map = {}  # Maps function signatures to their unique hash
#     for node in nodes:
#         hashed_name = f"{node.name}_{len(node.params)}_{node.class_name}_{)}"
#         hash_map[node.signature] = hashed_name

#     # Update function signatures, calls, and bodies
#     for node in nodes:
#         # Update function signature
#         node.signature = f"{hash_map[node.signature]}" if node.class_name else hash_map[node.signature]

#         # Update function calls
#         for i, (func_name, arg_count, class_name, param_types) in enumerate(node.calls):
#             original_sig = f"{class_name}::{func_name}({', '.join(param_types)})" if class_name else f"{func_name}({', '.join(param_types)})"
#             if original_sig in hash_map:
#                 node.calls[i] = (hash_map[original_sig], arg_count, class_name, param_types)

      
    # return nodes
def replace_function_names_with_hash(nodes: List[CppFunctionWrapperNode]) -> List[CppFunctionWrapperNode]:
    """Replaces function names and calls in function bodies with hashed identifiers."""
    
    hash_map = {}  # Maps function signatures to their unique hash

    for node in nodes:

        hashed_name = f"{node.name}|{len(node.params)}|{node.class_name}|{node.args}"
        hash_map[hashed_name] = node
        node.signature = hashed_name

    for node in hash_map.values():
       for i, (func_name, arg_count, class_name, param_types) in enumerate(node.calls):
            original_sig = f"{func_name}|{arg_count}|{class_name}|{param_types}"
            if original_sig in hash_map:
                node.calls[i] = (original_sig, arg_count, class_name, param_types)
        
      
    return nodes




# functions = analyze_cpp_code_from_string(cpp_source_code)
# hashed_functions = replace_function_names_with_hash(functions)

# # Print the updated functions
# for func in hashed_functions:
#     print(f"Class: {func.class_name if func.class_name else 'Global'}")
#     print(f"  Method: {func.name} -> Hashed: {func.signature}")
#     print(f"  Calls: {func.calls}")
#     print(f"  Body:\n{func.body}\n")
