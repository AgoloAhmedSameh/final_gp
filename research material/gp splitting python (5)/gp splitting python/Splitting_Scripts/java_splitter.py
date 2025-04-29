import javalang
from typing import Dict, Set, List, Tuple, Optional, Any
from dataclasses import dataclass

@dataclass
class JavaFunctionWrapperNode:
    """Represents a Java method with its properties."""
    name: str
    body: str
    calls: List[Tuple[str, int, List[str]]] = None  # (function_name, arg_count, [param_types])
    class_name: Optional[str] = None
    params: List[str] = None
    return_type: Optional[str] = None
    docstring: Optional[str] = None
    is_override: bool = False
    overloaded_variants: List['JavaFunctionWrapperNode'] = None
    signature: str = None
    def __post_init__(self):
        self.params = self.params or []
        self.calls = self.calls or []
        self.overloaded_variants = self.overloaded_variants or []
        if not self.signature and self.class_name and self.name:
            param_types = [p.split()[0] for p in self.params]  # Extract type from 'type name'
            self.signature = f"{self.class_name}.{self.name}({','.join(param_types)})"

def extract_body(node: javalang.tree.MethodDeclaration, source_lines: List[str]) -> str:
    """Extract the original method body from source code."""
    if not hasattr(node, 'position') or not node.position:
        return ""

    start_line = node.position.line - 1

    # Find the opening brace
    while start_line < len(source_lines) and '{' not in source_lines[start_line]:
        start_line += 1

    # Find the closing brace
    brace_count = 0
    end_line = start_line

    for i in range(start_line, len(source_lines)):
        line = source_lines[i]
        brace_count += line.count('{') - line.count('}')
        if brace_count == 0:
            end_line = i
            break

    return '\n'.join(source_lines[start_line:end_line + 1])

def get_type_string(type_node) -> str:
    """Convert a type node to string representation."""
    if isinstance(type_node, javalang.tree.ReferenceType):
        if hasattr(type_node, 'arguments') and type_node.arguments:
            args = ', '.join(get_type_string(arg) for arg in type_node.arguments)
            return f"{type_node.name}<{args}>"
        return type_node.name
    elif isinstance(type_node, javalang.tree.BasicType):
        return type_node.name
    return str(type_node)

def extract_calls(node: javalang.tree.MethodDeclaration) -> List[Tuple[str, int, List[str]]]:
    """
    Extract method calls with parameter types.
    Returns: List of tuples (method_name, arg_count, [param_types])
    """
    calls = []
    symbol_table = {}
    runtime_types = {}

    BUILT_IN_CLASSES = {
        'System', 'String', 'Integer', 'Double', 'Boolean', 'Math', 'Object',
        'List', 'ArrayList', 'Map', 'HashMap', 'Set', 'HashSet',
        'Collections', 'Arrays', 'StringBuilder', 'StringBuffer'
    }

    BUILT_IN_METHODS = {
        'toString', 'equals', 'hashCode', 'valueOf', 'println', 'print',
        'length', 'size', 'isEmpty', 'contains', 'remove'
    }

    def format_type(type_str: str) -> str:
        """Clean and format type strings."""
        if not type_str:
            return "Object"
            
        type_str = str(type_str)
        type_str = type_str.replace('TypeArgument(pattern_type=None, type=', '')
        type_str = type_str.replace('ReferenceType(', '')
        type_str = type_str.replace('arguments=', '')
        type_str = type_str.replace('dimensions=[]', '')
        type_str = type_str.replace('sub_type=None', '')
        type_str = type_str.replace('name=', '')
        type_str = type_str.replace(')', '')
        
        type_str = type_str.replace('[', '<')
        type_str = type_str.replace(']', '>')
        type_str = type_str.replace(', ', ',')
        
        type_str = type_str.replace(',,', ',')
        type_str = type_str.replace('><', '>')
        type_str = type_str.replace('  ', ' ')
        
        return type_str.strip()

    def format_generic_type(base_type: str, type_args: List) -> str:
        """Format generic type with its type arguments."""
        if not type_args:
            return base_type
            
        formatted_args = []
        for arg in type_args:
            if hasattr(arg, 'pattern_type') and arg.pattern_type:
                if arg.pattern_type == 'extends':
                    formatted_args.append(f"? extends {format_type(arg.type)}")
                elif arg.pattern_type == 'super':
                    formatted_args.append(f"? super {format_type(arg.type)}")
            else:
                formatted_args.append(format_type(arg.type))
                
        return f"{base_type}<{','.join(formatted_args)}>"

    def get_array_type(node) -> Tuple[str, int]:
        """Get base type and dimensions of an array."""
        if hasattr(node, 'type'):
            base_type = format_type(get_type_string(node.type))
            dims = len(node.type.dimensions) if hasattr(node.type, 'dimensions') else 0
            if hasattr(node, 'dimensions'):
                dims += len(node.dimensions)
            return base_type, dims
        return "Object", 0

    def infer_type(expr) -> str:
        """Infer the type of an expression."""
        if isinstance(expr, javalang.tree.Literal):
            if expr.value.startswith('"'):
                return "String"
            elif expr.value.isdigit():
                return "int"
            elif '.' in expr.value:
                return "double"
            elif expr.value in ['true', 'false']:
                return "boolean"
            elif expr.value == 'null':
                return "null"
            return "Object"
            
        elif isinstance(expr, javalang.tree.MethodInvocation):
            if expr.member.startswith('get') and expr.member[3:]:
                if expr.member.endswith('String'):
                    return 'String'
                elif expr.member.endswith('Int'):
                    return 'int'
                elif expr.member.endswith('Boolean'):
                    return 'boolean'
            return "Object"
            
        elif isinstance(expr, javalang.tree.BinaryOperation):
            if expr.operator in ['>', '<', '>=', '<=', '==', '!=']:
                return "boolean"
            elif expr.operator in ['+', '-', '*', '/']:
                return "numeric"
            return "Object"
            
        elif isinstance(expr, javalang.tree.MemberReference):
            var_name = expr.member
            return runtime_types.get(var_name, symbol_table.get(var_name, "Object"))
            
        elif isinstance(expr, javalang.tree.ArrayCreator):
            base_type = format_type(get_type_string(expr.type))
            dimensions = len(expr.dimensions) if hasattr(expr, 'dimensions') else 0
            return f"{base_type}{'[]' * dimensions}"
            
        elif isinstance(expr, javalang.tree.ClassCreator):
            if expr.type:
                type_name = expr.type.name
                if hasattr(expr.type, 'arguments') and expr.type.arguments:
                    return format_generic_type(type_name, expr.type.arguments)
                return type_name
            
        elif isinstance(expr, javalang.tree.Cast):
            base_type = format_type(get_type_string(expr.type))
            dims = get_array_dimensions(expr)
            return f"{base_type}{'[]' * dims}"

        return "Object"

    def update_symbol_table(node):
        """Update symbol table with variable declarations."""
        if isinstance(node, javalang.tree.LocalVariableDeclaration):
            if hasattr(node.type, 'arguments') and node.type.arguments:
                base_type = format_generic_type(node.type.name, node.type.arguments)
            else:
                base_type = format_type(get_type_string(node.type))
            
            dims = len(node.type.dimensions) if hasattr(node.type, 'dimensions') else 0
            
            for declarator in node.declarators:
                var_name = declarator.name
                
                total_dims = dims
                if hasattr(declarator, 'dimensions'):
                    total_dims += len(declarator.dimensions)
                
                if declarator.initializer:
                    if isinstance(declarator.initializer, javalang.tree.ArrayCreator):
                        init_type = format_type(get_type_string(declarator.initializer.type))
                        init_dims = len(declarator.initializer.dimensions)
                        final_type = f"{init_type}{'[]' * init_dims}"
                    elif isinstance(declarator.initializer, javalang.tree.ClassCreator):
                        init_type = format_type(get_type_string(declarator.initializer.type))
                        final_type = f"{init_type}{'[]' * total_dims}"
                    else:
                        final_type = f"{base_type}{'[]' * total_dims}"
                else:
                    final_type = f"{base_type}{'[]' * total_dims}"
                
                symbol_table[var_name] = final_type
                runtime_types[var_name] = final_type
                
        elif isinstance(node, javalang.tree.FormalParameter):
            if hasattr(node.type, 'arguments') and node.type.arguments:
                base_type = format_generic_type(node.type.name, node.type.arguments)
            else:
                base_type = format_type(get_type_string(node.type))
            
            dims = len(node.type.dimensions) if hasattr(node.type, 'dimensions') else 0
            final_type = f"{base_type}{'[]' * dims}"
            symbol_table[node.name] = final_type

    def visit_node(node):
        update_symbol_table(node)
        
        if isinstance(node, javalang.tree.SuperMethodInvocation):
            param_types = [format_type(infer_type(arg)) for arg in node.arguments]
            calls.append((f"super.{node.member}", len(node.arguments), param_types))

        if isinstance(node, javalang.tree.MethodInvocation):
            method_name = node.member
            qualifier = node.qualifier if node.qualifier else ""
            
            if (not qualifier.startswith(tuple(BUILT_IN_CLASSES)) and
                method_name not in BUILT_IN_METHODS):
                
                param_types = [format_type(infer_type(arg)) for arg in node.arguments]
                
                if qualifier:
                    if qualifier == "this":
                        calls.append((method_name, len(node.arguments), param_types))
                    else:
                        calls.append((f"{qualifier}.{method_name}", len(node.arguments), param_types))
                else:
                    calls.append((method_name, len(node.arguments), param_types))

        if hasattr(node, 'children'):
            for child in node.children:
                if isinstance(child, javalang.tree.Node):
                    visit_node(child)
                elif isinstance(child, list):
                    for item in child:
                        if isinstance(item, javalang.tree.Node):
                            visit_node(item)

    # Initialize symbol table with method parameters
    for param in node.parameters:
        if hasattr(param.type, 'arguments') and param.type.arguments:
            base_type = format_generic_type(param.type.name, param.type.arguments)
        else:
            base_type = format_type(get_type_string(param.type))
        
        dims = len(param.type.dimensions) if hasattr(param.type, 'dimensions') else 0
        final_type = f"{base_type}{'[]' * dims}"
        symbol_table[param.name] = final_type

    if node.body:
        for statement in node.body:
            visit_node(statement)

    return calls
def create_method_wrapper(node: javalang.tree.MethodDeclaration,
                         class_name: str,
                         source_code: str,
                         class_hierarchy: Dict) -> JavaFunctionWrapperNode:
    """Create a method wrapper node for a single method."""

    # Extract method body
    body = extract_body(node, source_code.splitlines())

    # Extract parameters
    params = []
    if node.parameters:
        for param in node.parameters:
            param_type = get_type_string(param.type)
            params.append(f"{param_type}")

    # Extract return type
    return_type = get_type_string(node.return_type) if node.return_type else "void"

    # Check for @Override annotation
    is_override = any(ann.name == 'Override' for ann in node.annotations)

    # Create signature
    param_types = [p.split()[0] for p in params]
    signature = f"{class_name}.{node.name}({','.join(param_types)})"

    # Extract method calls
    calls = extract_calls(node)

    return JavaFunctionWrapperNode(
        name=node.name,
        body=body,
        calls=calls,
        class_name=class_name,
        params=params,
        return_type=return_type,
        docstring=node.documentation if hasattr(node, 'documentation') else None,
        is_override=is_override,
        signature=signature,
        overloaded_variants=[]  # Will be populated later
    )

def analyze_java_code(source_code: str) -> Tuple[List[JavaFunctionWrapperNode], Dict[str, Any]]:
    """
    Analyze Java source code and return extracted information.
    """
    try:
        all_methods = []
        class_methods = {}  # Dictionary to group methods by class
        class_hierarchy = {}  # To track inheritance relationships

        tree = javalang.parse.parse(source_code)

        # First pass: collect class hierarchy
        for path, node in tree.filter(javalang.tree.ClassDeclaration):
            class_name = node.name
            class_hierarchy[class_name] = {
                'extends': node.extends.name if node.extends else None,
                'implements': [impl.name for impl in node.implements] if node.implements else [],
            }
            class_methods[class_name] = []

        # Second pass: collect all methods
        for path, node in tree.filter(javalang.tree.ClassDeclaration):
            class_name = node.name

            # Process each method in the class
            for method in node.methods:
                method_wrapper = create_method_wrapper(method, class_name, source_code, class_hierarchy)
                class_methods[class_name].append(method_wrapper)

        # Third pass: process overrides and overloads
        for class_name, methods in class_methods.items():
            # Group methods by name to identify overloads
            method_groups = {}
            for method in methods:
                if method.name not in method_groups:
                    method_groups[method.name] = []
                method_groups[method.name].append(method)

            # Process each group
            for method_name, group in method_groups.items():
                if len(group) > 1:  # Overloaded methods
                    for method in group:
                        # Create new nodes for each overloaded variant
                        variants = [m for m in group if m != method]
                        method.overloaded_variants = variants

                # Check for overrides
                parent_class = class_hierarchy[class_name].get('extends')
                if parent_class and parent_class in class_methods:
                    parent_methods = class_methods[parent_class]
                    for method in group:
                        for parent_method in parent_methods:
                            if (method.name == parent_method.name and
                                len(method.params) == len(parent_method.params)):
                                method.is_override = True

            all_methods.extend(methods)

        analysis_data = {
            "method_count": len(all_methods),
            "classes": set(method.class_name for method in all_methods),
            "class_hierarchy": class_hierarchy
        }

        return all_methods, analysis_data

    except javalang.parser.JavaSyntaxError as e:
        raise ValueError(f"Invalid Java code: {str(e)}")