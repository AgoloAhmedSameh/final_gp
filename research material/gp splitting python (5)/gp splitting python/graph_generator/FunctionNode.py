from typing import List

class FunctionNode:
    def __init__(self,
                 Function_Name: str = None,
                 FunctionsCallsInside: List[str] = None,
                 #new
                 Hashed : str=None,
                 ClassNameIfExist: str = None,
                 Arguments: List[str] = None,
                 FunctionBody: str = None,
                 Description: str = None):
        
        self._ID = -1
        self._Function_Name = Function_Name
        self._FunctionsCallsInside = FunctionsCallsInside if FunctionsCallsInside else []

        self._ClassNameIfExist = ClassNameIfExist
        self._Arguments = Arguments if Arguments else [] 
        self._FunctionBody = FunctionBody
        self._Description = Description
        self._Hashed = Hashed
        self.Istested=False
        
    # def __hash__(self):
    #     return f"{self._Function_Name}|{self._ClassNameIfExist}|{len(self._Arguments)}|{self._Arguments}"

    def get_ID(self):
        return self._ID

    def get_Function_Name(self):
        return self._Function_Name

    def get_FunctionsCallsInside(self):
        return self._FunctionsCallsInside

    def get_ClassNameIfExist(self):
        return self._ClassNameIfExist

    def get_Arguments(self):
        return self._Arguments

    def get_FunctionBody(self):
        return self._FunctionBody

    def get_Description(self):
        return self._Description
    
    def get_hashed(self):
        return self._Hashed
    
    # Setters
    def set_ID(self, ID: int):
        self._ID = ID
    
    def set_Function_Name(self, Function_Name: str):
        self._Function_Name = Function_Name
    
    def set_FunctionsCallsInside(self, FunctionsCallsInside: List[str]):
        self._FunctionsCallsInside = FunctionsCallsInside
    
    def set_ClassNameIfExist(self, ClassNameIfExist: str):
        self._ClassNameIfExist = ClassNameIfExist

    def set_hashed(self, Signature : str):
        self._Hashed = Signature
    
    def set_Arguments(self, Arguments: List[str]):
        self._Arguments = Arguments
    
    def set_FunctionBody(self, FunctionBody: str):
        self._FunctionBody = FunctionBody
    
    def set_Description(self, Description: str):
        self._Description = Description
    
    def __str__(self):
        return (f"FunctionNode(ID={self._ID}, Function_Name='{self._Function_Name}', "
                f"FunctionsCallsInside={self._FunctionsCallsInside}, ClassNameIfExist='{self._ClassNameIfExist}',hashing='{self._Hashed}', "
                f"Arguments={self._Arguments}, FunctionBody='{self._FunctionBody}', Description='{self._Description}')")