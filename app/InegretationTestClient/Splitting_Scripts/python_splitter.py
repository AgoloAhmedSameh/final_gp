import ast
from typing import Dict, Set, List, Tuple, Optional, Any
from dataclasses import dataclass

class FunctionWrapperNode:
    """Represents a function or method with its properties."""
    name: str
    body: str
    calls: List[Tuple[str, int]]  # (function_name, arg_count)
    class_name: Optional[str] = None
    params: List[str] = None
    decorators: List[str] = None
    return_type: Optional[str] = None
    docstring: Optional[str] = None
    is_override: bool = False
    original_class: Optional[str] = None
    #Signituare to store hashing 
    Signituare : str
    
    def __post_init__(self):
        self.params = self.params or []
        self.decorators = self.decorators or []

class CodeAnalyzer(ast.NodeVisitor):
    """Advanced code analyzer that extracts various code elements."""
    
    def __init__(self):
        self.functions: Dict[Tuple[str, Optional[str]], List[Dict[str, Any]]] = {}
        self.classes: Dict[str, Dict[str, Any]] = {}
        self.current_class: Optional[str] = None
        self.current_scope: List[str] = []
        self.object_types: Dict[str, str] = {}
        self.imports: Dict[str, str] = {}
        self.call_graph: Dict[str, Set[str]] = {}
        self.method_hierarchy: Dict[str, List[str]] = {}

    def extract_calls(self, node: ast.AST, class_info: Dict = None) -> List[Tuple[str, int, str]]:
        """
        Extract function calls returning (method_name, arg_count, class_name).
        class_info should contain:
        - parent_class: name of parent class if analyzing a child class
        - current_class: name of current class being analyzed
        """
        calls = []
        
        # Track variable assignments
        variable_types = {}
        
        for n in ast.walk(node):
            # Track variable assignments
            if isinstance(n, ast.Assign):
                if isinstance(n.value, ast.Call) and isinstance(n.value.func, ast.Name):
                    # Case: obj = MathOperations()
                    if len(n.targets) == 1 and isinstance(n.targets[0], ast.Name):
                        variable_types[n.targets[0].id] = n.value.func.id

            # Extract calls
            if isinstance(n, ast.Call):
                if isinstance(n.func, ast.Name):
                    # Direct function call
                    calls.append((n.func.id, len(n.args), "Unknown"))
                elif isinstance(n.func, ast.Attribute):
                    method_name = n.func.attr
                    caller = n.func.value
                    
                    if isinstance(caller, ast.Name):
                        caller_name = caller.id
                        if caller_name == "super" and class_info and 'parent_class' in class_info:
                            # Super call - use parent class
                            calls.append((method_name, len(n.args), class_info['parent_class']))
                        elif caller_name in variable_types:
                            # Use the tracked variable type
                            calls.append((method_name, len(n.args), variable_types[caller_name]))
                        else:
                            calls.append((method_name, len(n.args), caller_name))
                    else:
                        calls.append((method_name, len(n.args), "Unknown"))
        
        return calls
    def extract_parameters(self, node: ast.FunctionDef) -> List[Dict[str, Any]]:
        """Extract detailed parameter information."""
        params = []
        for arg in node.args.args:
            if arg.arg!="self":
                params.append(arg.arg)
        return params

    def extract_decorators(self, node: ast.AST) -> List[str]:
        """Extract decorator information."""
        return [ast.unparse(dec) for dec in getattr(node, 'decorator_list', [])]

    def extract_return_type(self, node: ast.FunctionDef) -> Optional[str]:
        """Extract return type annotation if present."""
        return ast.unparse(node.returns) if node.returns else None

    def check_override(self, func_name: str) -> Tuple[bool, Optional[str]]:
        """Check if a method is overridden from a parent class."""
        if not self.current_class:
            return False, None
            
        current_class = self.classes.get(self.current_class, {})
        base_classes = current_class.get('bases', [])
        
        for base in base_classes:
            base_name = base.split('.')[-1]  # Handle potential module paths
            if base_name in self.classes:
                if func_name in self.classes[base_name]['methods']:
                    return True, base_name
        return False, None

    def visit_FunctionDef(self, node: ast.FunctionDef) -> None:
        """Process function definitions with enhanced metadata extraction."""
        func_name = node.name
        scope = ".".join(self.current_scope + [func_name])
        
        is_override, original_class = self.check_override(func_name)
        
        # Extract function metadata
        metadata = {
            "body": ast.unparse(node),
            "calls": self.extract_calls(node),
            "class_name": self.current_class,
            "params": self.extract_parameters(node),
            "decorators": self.extract_decorators(node),
            "return_type": self.extract_return_type(node),
            "docstring": ast.get_docstring(node),
            "scope": scope,
            "lineno": node.lineno,
            "is_override": is_override,
            "original_class": original_class
        }
        
        # Initialize list for this function if it doesn't exist
        key = (func_name, self.current_class)
        if key not in self.functions:
            self.functions[key] = []
        
        # Add the new function metadata
        self.functions[key].append(metadata)
        
        # Update class methods if within a class
        if self.current_class:
            self.classes[self.current_class]['methods'].add(func_name)
        
        self.generic_visit(node)

    def visit_ClassDef(self, node: ast.ClassDef) -> None:
        """Process class definitions and their contents."""
        prev_class = self.current_class
        self.current_class = node.name
        self.current_scope.append(node.name)
        
        # Extract class metadata
        self.classes[node.name] = {
            "bases": [ast.unparse(base) for base in node.bases],
            "decorators": self.extract_decorators(node),
            "docstring": ast.get_docstring(node),
            "methods": set(),
            "attributes": set()
        }
        
        self.generic_visit(node)
        self.current_scope.pop()
        self.current_class = prev_class

    def visit_Import(self, node: ast.Import) -> None:
        """Track imports."""
        for alias in node.names:
            self.imports[alias.asname or alias.name] = alias.name

    def visit_ImportFrom(self, node: ast.ImportFrom) -> None:
        """Track from-imports."""
        module = node.module or ''
        for alias in node.names:
            self.imports[alias.asname or alias.name] = f"{module}.{alias.name}"

    def get_functions(self) -> List[FunctionWrapperNode]:
        """Return analyzed functions as FunctionWrapperNode objects."""
        function_nodes = []
        for (name, class_name), function_versions in self.functions.items():
            for func_data in function_versions:
                function_nodes.append(
                    FunctionWrapperNode(
                        name=name,
                        body=func_data["body"],
                        calls=list(func_data["calls"]),
                        class_name=func_data["class_name"],
                        params=func_data["params"],
                        decorators=func_data["decorators"],
                        return_type=func_data["return_type"],
                        docstring=func_data["docstring"],
                        is_override=func_data["is_override"],
                        original_class=func_data["original_class"]
                    )
                )
        return function_nodes

def analyze_python_code(source_code: str) -> Tuple[List[FunctionWrapperNode], Dict[str, Any]]:
    """
    Analyze source code and return extracted information.
    
    Args:
        source_code: The source code to analyze
        
    Returns:
        Tuple containing:
        - List of FunctionWrapperNode objects
        - Dictionary with additional analysis data
    """
    try:
        tree = ast.parse(source_code)
        analyzer = CodeAnalyzer()
        analyzer.visit(tree)
        
        analysis_data = {
            "classes": analyzer.classes,
            "imports": analyzer.imports,
            "object_types": analyzer.object_types,
            "call_graph": analyzer.call_graph,
            "method_hierarchy": analyzer.method_hierarchy
        }
        
        return analyzer.get_functions(), analysis_data
    except SyntaxError as e:
        raise ValueError(f"Invalid Python code: {str(e)}")
    
    

def replace_function_names_with_hash(nodes: List[FunctionWrapperNode]) -> List[FunctionWrapperNode]:
    """Replaces function names and calls in function bodies with hashed identifiers."""
    
    hash_map = {}  # Maps function signatures to their unique hash

    # Generate unique hashes for function names
    for node in nodes:
        hashed_name = f"{node.name}|{len(node.params)}|{node.class_name}"
        hash_map[hashed_name] = node
        node.Signituare= hashed_name 

    # Replace function call names with their respective hash values
    for node in nodes:
        for i, (func_name, arg_count, class_name) in enumerate(node.calls):
            original_sig = f"{func_name}|{arg_count}|{class_name}"
            if original_sig in hash_map:
                node.calls[i] = (original_sig, arg_count, class_name)
        
    return nodes
