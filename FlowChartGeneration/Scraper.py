from abc import ABC, abstractmethod
from Graph import Graph, Node
from collections import deque, defaultdict
from RQueue import RQueue
from Enums import LineType
from Formater import Formater
from helpers import ClearStrings, RemoveMultilineComments
import re

class Scraper(ABC):

    @property
    @abstractmethod
    def _PreProcessLine(self, line_of_code:str) -> bool:
        """
            pre process the line and make it ready for processing and indicate wtheter it's a valid line to process or not like (comments, decorators, ...)
        """
        pass

    @property
    @abstractmethod
    def _ProcessLine(self,line_number ,line_of_code:str) -> None:
        pass

    @property
    @abstractmethod
    def _Process(self) -> None: 
        pass

    @property
    def _PostProcess(self) -> None:
        pass



    def _GetIndentationValueOfLine(self, line_number):
        return self._indentation_value[line_number]
    def _GetLineType(self, line_number):
        return self._line_type[line_number]

    def _GetBranchesParent(self, line_number, indentation_value, parent_allowed_types = [LineType.Procedural, LineType.Loop], exact_indentation_value=False, reverse=False) -> int:

        for i in range(line_number - 1, -1, -1):
            current_indentation = self._GetIndentationValueOfLine(i)
            if self._GetLineType(i) in parent_allowed_types and (current_indentation == indentation_value and exact_indentation_value or not exact_indentation_value and (current_indentation <= indentation_value and not reverse or current_indentation >= indentation_value and reverse)):
                return i
        return -2 # START node

    def __FindIndex(self, line_of_code, keywords):
        index = None
        for keyword in keywords:
            keyword_index = line_of_code.find(keyword)
            if(keyword_index != -1):
                if index == None:
                    index = keyword_index
                else:
                    index = min(index, keyword_index)
        return index

    def _FindLoopIndex(self, line_of_code):
        return self.__FindIndex(line_of_code, self._loop_keywords)

    def _FindConditionIndex(self, line_of_code):
        return self.__FindIndex(line_of_code, self._splitting_keywords)
    

    def __init__(self, code:str) -> None:

        """
            this Class represent an abstract Scrapper of the Nodes, edges of the flowchart for all the inherited languages

            - each child class should has it's own meta data vars to specify it's own rules some of them are shared

            - there's 3 main methods that should be abstract to process each line according to it's corresponding language
            - PreProcess
            - Process
            - PostProcess
            
             
            Attributes:
                code (str): the input code script
                
        """
        self.code = code
        self.graph = Graph()

        # Mainly in the class implementation the "line_number" of the current code is considered the identifer of the current Node to process


        self._loop_keywords = [] # list of all loop keywords
        # meta data vars: ====================================================
        self._splitting_keywords = [] # list of all branches (if-conditions keywords)

        # each element in the stack is an index to the line code
        self._stack_of_loops = deque()
        self._stack_of_loops_indentation_value = deque()
        self._stack_of_blocks = deque()

        self._linking_requests = RQueue()

        self._last_loop = {}
        self._line_type = {}
        self._existing_condition_keyword = {}
        self._existing_loop_keyword = {}
        self._indentation_value = defaultdict(int)
        self._block_id = {}

        self.code = RemoveMultilineComments(code)

        self.lines_of_code = self.code.splitlines()
        # ====================================================================

        self._last_loop[-1] = self._last_loop[-2] = -1

        self.graph.AddNode(-2,"Start",shape='oval',color='chartreuse4',fontcolor='white')
        self.graph.AddNode(-1,"End",shape='oval',color='red',fontcolor='white')
        self._line_type[-2] = self._line_type[-1] = LineType.Procedural

