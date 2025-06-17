from typing import List, Any
from app.InegretationTestClient.Splitting_Scripts import python_splitter,java_splitter,Cpp_Splitter,JS_Splitter
from app.InegretationTestClient.graph_generator.FunctionNode import FunctionNode
from app.InegretationTestClient.graph_generator.Graph_Constructor import graph
import re
class Tester:
    def __init__(self,AgentCode):
        self.AgentCode=AgentCode
    def test(self, File: str, LanguageName: str) -> List[Any]:  
        #Identify Js or Not 
        Is_JS= False 
       
        if LanguageName=="python":
            Functions=self.pycode(File=File)
        elif LanguageName=="java":
            Functions=self.javacode(File=File)
        elif LanguageName=="cpp":
            Functions=self.cppcode(File=File)
        elif LanguageName=="javascript":
            Is_JS = True
            Functions = self.Jscode(File=File)
        

        if Is_JS == False:
         functionsNodes=[]
         for i in Functions:
            functionsNodes.append(FunctionNode(
            Function_Name=i.name,
            FunctionsCallsInside=i.calls,
            Hashed=i.signature,
            ClassNameIfExist=i.class_name,
            Arguments=i.args,
            FunctionBody=i.body,
            Description=""
    ))
            
         graph_=graph(functionsNodes)
         graph_.construct_Graph()
         Sorted_FunctionNodes,Sorted_FunctionNames=graph_.Topological_Sort()

        #As js already returns Objects 
        if Is_JS == True:
         graph_=graph(Functions)
         graph_.construct_Graph(1)
         Sorted_FunctionNodes,Sorted_FunctionNames=graph_.Topological_Sort(1)

        Asserts=[]
        for function in Sorted_FunctionNodes:
            # node=Sorted_FunctionNames[function.split("|")[0]]
            print(function)
            if len(function.get_FunctionsCallsInside())==0:
                system_prompt = f"""

                Your task is to create 5 test cases for this function The code passed is in cpp do not convert to another language

                    - Use the Function sent 
                    - Do not create a new Function
                    - The test cases should cover both basic and edge scenarios to ensure the function works correctly.
                    - The expected output should be assert statements only.
                the Function is inside class name {function.get_ClassNameIfExist()}
                then you need to start your code with if the class not (None or Unknown):
                ```{LanguageName}
                imports/includes
                class {function.get_ClassNameIfExist()}
                    ...the target function or functions...
                ```
                Create the class if exist and the copy the function inside then make an object to test it
                Make sure to write Ready to execute code to run it directly (Make a Start Point and Call)
                Write the code inside:
                ```{LanguageName}
                ...your code here...
                ```
                """
                print("unit")
                testcases=self.AgentCode(system_prompt,function.get_FunctionBody())
                print("---------")
                print(testcases)
                pattern = rf"```{LanguageName}\n(.*?)```"
                testcases=re.findall(pattern, testcases, re.DOTALL)
                print("---------")
                Asserts.append((function.get_FunctionBody(),testcases))
                function.Istested=True
            elif len(function.get_FunctionsCallsInside())!=0:
                code=""
                code+=function.get_FunctionBody()+"\n"

                for neighbor in function.get_FunctionsCallsInside():

                    if neighbor[0] in Sorted_FunctionNames:
                        # for neighborNode in Sorted_FunctionNames[neighbor[0]].items():

                            # if neighbor[1]==len(neighborNode[1].get_Arguments()):
                                # if LanguageName!="python" and LanguageName!="javascript":
                                #   code+=neighborNode[1].get_FunctionBody()+"\n"
                                # if neighborNode[1].get_Function_Name!=neighborNode[0]:
                                #     for argidx in range(len(neighborNode[1].get_Arguments())):
                                #         arg=neighborNode[1].get_Arguments()[argidx]

                                #         if arg!= neighbor[2][argidx]:
                                #             break
                                code+= Sorted_FunctionNames[neighbor[0]].get_FunctionBody()+"\n"      
                                print("This Is The full Code after checking calls")
                                print(code)  

                if code== function.get_FunctionBody()+"\n":
                    print("unit")
                    system_prompt = f"""
                    Your task is to create 5 test cases for this function.
                   - The test cases should cover both basic and edge scenarios to ensure the function works correctly.
                   - The expected output should be assert statements only.
                    the Function is inside class name {function.get_ClassNameIfExist()}
                    then you need to start your code with if the class not (None or Unknown):
                    ```{LanguageName}
                    imports/includes
                    class {function.get_ClassNameIfExist()}
                    // The target function(s) will be placed here...
                    
                    ```
                    Create the class if exist and the copy the function inside then make an object to test it
                    
                    Write the code inside:
                    ```{LanguageName}
                    ...your code here...
                    ```
                    """
                    testcases=self.AgentCode(system_prompt,function.get_FunctionBody())
                    print("---------")
                    print(testcases)
                    pattern = rf"```{LanguageName}\n(.*?)```"
                    testcases=re.findall(pattern, testcases, re.DOTALL)
                    print("---------")


                    Asserts.append(function.get_FunctionBody(),testcases)
                    function.Istested=True
                else:
                    # print("stub")
                    # system_prompt = f"""
                    # Given the following Python function and its dependencies,  
                    # replace the children's functions' implementations with stub (dummy)  
                    # versions that return fixed values of the appropriate type (e.g., integers, lists, dictionaries).  
                    # Target Function :{node[function].get_Function_Name()}
                    # Create the class if exist and the copy the function inside then make an object to test it

                    # the Function is inside class name {node[function].get_ClassNameIfExist()}
                    # then you need to start your code with if the class not (None or Unknown):
                    # ```{LanguageName}
                    # class {node[function].get_ClassNameIfExist()}:
                    #     ...the target function or functions...
                    # ```

                    # **Strict Requirement:** Do NOT modify the body of the parent function in any way.  
                    # Only modify the bodies of its dependent (child) functions.  
                    # The expected output is a code file containing the modified functions with no additional code (e.g., no main block).  
                    
                    # Write the code inside:
                    # ```{LanguageName}
                    # ...your code here...
                    # ```
                    # """
                    # StubCode=self.AgentCode.generate_code(code,system_prompt)
                    # print("code : ",code)
                    # print("---------")
                    # print("stubs : ",StubCode)
                    # print("---------")
                    # system_prompt = f"""
                    # Your task is to create 5 test cases for the parent function.
                    #     - The test cases should cover both basic and edge scenarios to ensure the function works correctly.

                    # Target Function :{node[function].get_Function_Name()} 
                    # the Function is inside class name {node[function].get_ClassNameIfExist()}
                    # then you need to start your code with if the class not (None or Unknown):
                    # ```{LanguageName}
                    # class {node[function].get_ClassNameIfExist()}:
                    #     ...the target function or functions...
                    # ```
                    # Create the class if exist and the copy the function inside then make an object to test it

                    # The function is already provided along with its stubs (Note each stub returns fixed values or data structer). 
                    # The expected output should be assert statements not unittest.
                    # Note the the returns from the functions is a fixed values

                    # **Make sure to write Ready to execute code to run it directly (Make a Start Point and Call)**
                    # Example:
                    # ```{LanguageName}
                    # def main():
                    #     **Asserts here/Test Cases**

                    # main()

                    # Write the code inside:
                    # ```{LanguageName}
                    # ...your code here...
                    # ``` 
                    # """
                    # testcases=self.AgentCode.generate_code(StubCode,system_prompt)
                    # print("stubs testcases : ",testcases)
                    # Asserts.append((StubCode,testcases))

                    system_prompt = f"""
                    As a Software Tester, your role is to generate an **integration test suite** for a **target function** that depends on other functions.
                    Provide **5 distinct assert statements** to rigorously validate the integration between the target function and its dependencies.
                    - The test cases should cover both **basic and edge scenarios** to ensure the function works correctly.

                   ***Follow these guidelines***:
                  1. **Understand** the purpose and logic of the function based on its description and code.
                  2. **Generate test cases directly** without any additional classes—use `assert()` only.
                  3. **Include both Basic and Advanced Test Cases**.
                    Assert Format:

                    assert(target_function(arg1, arg2, ...) == expected_result); //For each test

                    Add a comment explaining the purpose of each test (e.g., # Test mixed positive/negative inputs).
                    Make sure to write Ready to execute code to run it directly (Make a Start Point and Call)
                    Target Function :{function.get_Function_Name()} 
                    The expected output should be assert statements not unittest.
                    Write the code inside:
                    ```language
                    ...your code here...
                    ``` 
                    """

                    testcases=self.AgentCode(system_prompt,code)
                    print("---------")
                    print("integration testcases :",testcases)
                    print("---------")
                    Asserts.append((code,testcases))
                    function.Istested=True

        return Asserts
    def pycode(self,File:str)->List[Any]:
        
        Functions=python_splitter.analyze_python_code(File)
        if not Functions:  # Check if Functions is empty
         print("Error: No functions extracted from the C++ code.")
         return []
        New_Functions = python_splitter.replace_function_names_with_hash(Functions)
        for i in New_Functions:
         print(i)
        return New_Functions
    
    def javacode(self,File:str)->List[Any]:
        Functions=java_splitter.analyze_java_code(File)
        return Functions
    def cppcode(self, File: str) -> List[Any]:
     Functions = Cpp_Splitter.analyze_cpp_code_from_string(File)
     if not Functions:  # Check if Functions is empty
        print("Error: No functions extracted from the C++ code.")
        return []
    
     New_Functions = Cpp_Splitter.replace_function_names_with_hash(Functions)
     for i in New_Functions:
         print(i)
     print("Extracted functions:", New_Functions)
     return New_Functions
    
    def Jscode(self, File: str) -> List[Any]:
     Functions = JS_Splitter.extract_functions(File)
     if not Functions:  # Check if Functions is empty
        print("Error: No functions extracted from the js code.")
        return []
     functionsNodes = []
     for i in Functions:
       functionsNodes.append(FunctionNode(
        Function_Name=i.name,
        Hashed=i.hash,
        FunctionsCallsInside=i.calls,
        ClassNameIfExist=i.class_name,
        Arguments=i.params,
        FunctionBody=i.body,
        Description=""
    ))
     
     for i in functionsNodes:
         print(i)
     print("Extracted functions:", functionsNodes)
     return functionsNodes

