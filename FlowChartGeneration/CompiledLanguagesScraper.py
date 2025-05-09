import pdb
from Graph import Graph, Node
from collections import deque, defaultdict
from RQueue import RQueue
from Enums import LineType, ProgrammingLanguages
from Formater import Formater
import helpers
import sys



from Scraper import Scraper
class CompiledLanguagesScraper(Scraper):
    def __init__(self, code, programming_language , export_path = "", include_macros=False, get_frames=False, output_format=None):

        formatted_code = None
        
        if programming_language == ProgrammingLanguages.CPP:
            formatted_code = Formater.CPP(code)
        elif programming_language == ProgrammingLanguages.JAVA:
            formatted_code = Formater.Java(code)
        else:
            formatted_code = Formater.JavaScript(code)

        super().__init__(formatted_code)

        self.programming_language = programming_language
        # meta data vars: =============================================
        self._loop_keywords = ['do','while','for']
        self._splitting_keywords = ['else if', 'if','else']
        
        self._stack_of_doos = deque()
        self._stack_of_switches = deque()
        self._stack_of_switches_indentation_value = deque()

        self.uniform_indentation_value = 1

        self.splitting_point = False

        self._include_macros = include_macros

        self.processed_lines = []
        # ====================================================================

        self._Process()
        self._PostProcess()
        
        # for node_id in self.graph.nodes:
        #     print(node_id, self.graph.nodes[node_id].data)

        # for node_id in self.graph.nodes:
        #     print(node_id, self.graph.nodes[node_id].childs)

        self.simulation_paths = self.graph.ExportGraph(self._line_type, path=export_path,get_frames=get_frames, format=output_format)
        self.graph.DisplayGraph(path=export_path)

        # for i, node in enumerate(self.graph.nodes.values()):
        #     if i - 2 >= 0:
        #         print(i - 2, end='\t\t\t|')
        #         print(self._line_type[i - 2], end='\t|')
        #         print(self._block_id[i - 2], end='\t|\t')
        #     print(node.data)
        # print("the full export path is: " + export_path)


    def _ProcessLine(self, line_number, line_of_code):
        self.processed_lines.append(line_of_code)
        # print(line_of_code)
        
        """
            the return value is either 0 or 1 meaning it will be counted as node or not
        """
        # for debugging
        if line_number == 21:
            pass
        # ====================================== Indentation value calculation =============================================

        # the indentation value in C++ is based upon the curly brackets it's initially is zero
        current_indentation_value = self._GetIndentationValueOfLine(line_number)
        query_string = helpers.ClearStrings(line_of_code.strip())

        self.splitting_point = False

        if '{' == query_string:
            self._stack_of_blocks.append(line_number - 1)
            self._indentation_value[line_number] = current_indentation_value + 1
            return 0
        elif '}' == query_string:
            self._stack_of_blocks.pop()
            self._indentation_value[line_number] = current_indentation_value - 1
            return 0
        
        if len(self._stack_of_blocks) == 0:
            self._block_id[line_number] = None
        else:
            self._block_id[line_number] = self._stack_of_blocks[-1]

        self._indentation_value[line_number + 1] = current_indentation_value 


        # Console Debugging:
        # print(f"line number = {line_number}", f"current_block = {self._block_id[line_number]}", f"current_indentation_value = {current_indentation_value}", "\t\t\t", line_of_code, '\n')

        # ======================================== Local Vars ==============================================================
        last_loop_index = self._FindLoopIndex(query_string)
        last_Condition_index = self._FindConditionIndex(query_string)
        current_line_type = None
        # ============================ Initializing the current Node =======================================================

        self.graph.AddNode(line_number, line_of_code.strip())
        if line_number == 0:
            self.graph.AddEdge(-2, line_number)


        if(
            current_indentation_value < self._indentation_value[line_number - 1] 
            and (
                len(self._stack_of_loops_indentation_value) > 0 and current_indentation_value <= self._stack_of_loops_indentation_value[-1] 
                or
                len(self._stack_of_switches_indentation_value) > 0 and current_indentation_value <= self._stack_of_switches_indentation_value[-1]
            )
        ):

            for node_id in self._linking_requests.GetNodes(current_indentation_value):
                last_possible_parent_loop = self._last_loop[self._last_loop[node_id] - 1]
                if last_possible_parent_loop != -1 and self._GetIndentationValueOfLine(last_possible_parent_loop) < self._GetIndentationValueOfLine(self._last_loop[node_id]):
                    self.graph.AddEdge(node_id, last_possible_parent_loop,weight_value='NEXT ITERATION', color="#17AFAF")
                else:
                    self.graph.AddEdge(node_id, line_number)

            self._linking_requests.Pop(current_indentation_value)

            # if self._line_type[self._block_id[line_number - 1]] == LineType.Loop:
            while(len(self._stack_of_loops) > 0 and current_indentation_value <= self._stack_of_loops_indentation_value[-1]):
                self._stack_of_loops.pop()
                self._stack_of_loops_indentation_value.pop()
            # else:
            while(len(self._stack_of_switches) > 0 and current_indentation_value <= self._stack_of_switches_indentation_value[-1]):
                self._stack_of_switches.pop()
                self._stack_of_switches_indentation_value.pop()

        # ============================= Detect the current line type =======================================================
        if(last_loop_index == 0 and 'double' != query_string[:len('double')]): # corner case: if the double is the first keyword in the line it will be considered a do while loop; so we don't want that!
            current_line_type = LineType.Loop

            for loop_keyword in self._loop_keywords:
                if loop_keyword in query_string:
                    if loop_keyword == 'do':
                        self._stack_of_doos.append(current_indentation_value)
                    if loop_keyword == 'while' and len(self._stack_of_doos) != 0 and current_indentation_value == self._stack_of_doos[-1]:
                        self._stack_of_doos.pop()
                        current_line_type = LineType.Procedural
                        break

                    self._stack_of_loops.append(line_number)
                    self._stack_of_loops_indentation_value.append(current_indentation_value)
                    break
            
        elif (last_Condition_index == 0):
            current_line_type = LineType.Condition

            for condition_keyword in self._splitting_keywords:
                if condition_keyword in query_string:
                    self._existing_condition_keyword[line_number] = condition_keyword
                    break
        
        elif ('switch' in query_string):
            current_line_type = LineType.SwitchStatement
            self._stack_of_switches.append(line_number)
            self._stack_of_switches_indentation_value.append(current_indentation_value)
        else:
            if 'continue' in query_string:
                current_line_type = LineType.TerminatorOfLoop
                self.graph.AddEdge(line_number, self._stack_of_loops[-1], color='#17AFAF', weight_value='NEXT ITERATION')
            elif 'break' in query_string:


                parent_line_number = self._block_id[line_number]
                parent_block_type = self._line_type[parent_line_number]

                while parent_block_type != LineType.Loop and parent_block_type != LineType.SwitchStatement:
                    parent_line_number = self._block_id[parent_line_number]
                    parent_block_type = self._line_type[parent_line_number]

                if parent_block_type == LineType.Loop:
                    current_line_type = LineType.TerminatorOfLoop
                else:
                    current_line_type = LineType.TerminatorOfSwitch

                self._linking_requests.Push(line_number, self._GetIndentationValueOfLine(parent_line_number))

            elif 'return' in query_string:
                current_line_type = LineType.TerminatorOfProgram			
                self.graph.AddEdge(line_number, -1)
            elif 'co_yield' in query_string and self.programming_language == ProgrammingLanguages.CPP or 'yield' in query_string and self.programming_language == ProgrammingLanguages.JavaScript:
                current_line_type = LineType.TerminatorOfProgram
                self.graph.AddEdge(line_number, -1)
            else:
                current_line_type = LineType.Procedural

        self._line_type[line_number] = current_line_type

        if current_line_type == LineType.Loop or current_line_type == LineType.Condition:
            self.splitting_point = True
        # ============================= customizing Node color based on it's type ==========================================
        
        node_color = '#eeeeee'
        node_shape = 'rectangle'
        font_color = 'black'

        if current_line_type in [LineType.Condition, LineType.SwitchStatement] or 'case' == query_string[:4] or 'default:' == query_string[:8]:
            node_color = '#17AFAF'#'darkkhaki'
            node_shape = 'diamond'
            font_color = 'white'
        elif current_line_type == LineType.Loop or 'while' in query_string:
            node_color = '#17AFAF' #'#686D76'
            node_shape = 'rarrow'
            font_color = 'white'


        self.graph.AddNode(line_number, line_of_code.strip(), node_shape, color=node_color,fontcolor=font_color)

        # ============================= getting the previous node ==========================================================


        # Not a Terminator
        parent_allowed_types = [LineType.Procedural, LineType.Loop, LineType.Condition, LineType.SwitchStatement]
        prev_node_id = self._GetBranchesParent(line_number, current_indentation_value, parent_allowed_types)


        
        weight_value = ''
        font_color = 'black'

        if(self._GetLineType(prev_node_id) == LineType.Condition):
            if(self._GetIndentationValueOfLine(prev_node_id) == current_indentation_value):
                weight_value = 'FALSE'
                font_color = 'red'
            else:
                weight_value = 'TRUE'
                font_color = 'darkgreen'
        if(self._GetLineType(prev_node_id) == LineType.Loop):
            if(self._GetIndentationValueOfLine(prev_node_id) == current_indentation_value):
                weight_value = 'OUT'
                font_color = 'red'
            else:
                weight_value = 'BODY'
                font_color = 'darkgreen'
        if(self._GetLineType(prev_node_id) == LineType.SwitchStatement):
            weight_value = 'OUT'
            font_color = 'red'


        prev_node_code = self.graph.nodes[str(prev_node_id)].data

        if 'case' == query_string[:4] or 'default:' == query_string[:8]:
            prev_node_id = self._stack_of_switches[-1]

        if not (
                prev_node_code.strip()[:4] == 'else' and not prev_node_code.strip()[:7] == 'else if' and weight_value == 'FALSE'
                or
                len(self.graph.nodes[str(prev_node_id)].childs) == 1 and self._line_type[prev_node_id] == LineType.Procedural
            ):
            self.graph.AddEdge(prev_node_id, line_number, weight_value, font_color=font_color)


        if len(self._stack_of_loops) > 0:
            self._last_loop[line_number] = self._stack_of_loops[-1]
        else:
            self._last_loop[line_number] = -1

        return 1


    def _PreProcessLine(self, line_of_code:str):
        if(len(line_of_code) == 0 or len(line_of_code) == 1 and line_of_code[0] == ';'):
            return False
        
        query_string = helpers.ClearStrings(line_of_code)

        # comments or (macros (if not allowed!))
        if(query_string[0:2] == '//' or (query_string[0] == '#' and not self._include_macros)):
            return False
        
        return True



    def _PostProcess(self):
        for id in range(self.graph.Size() - 2): # not counting the start and the end nodes
            current_node = self.graph.GetNode(id)
            line_type = self._GetLineType(id)
            
            # for debugging
            if id == 21:
                pass

            # 1 - check if it's problematic line:
                # problematic line if the current line not a terminator and it's a leaf node or a condition or a loop that is missing a branch except for else

            if line_type not in [LineType.TerminatorOfLoop, LineType.TerminatorOfProgram, LineType.TerminatorOfSwitch] and (
                len(current_node.childs) == 0 or (
                    len(current_node.childs) < 2 and line_type in [LineType.Condition, LineType.Loop] and not (
                        line_type == LineType.Condition and self._existing_condition_keyword[id] == 'else'
                    ) 
                )
            ):
                #2 - We need to find the valid next path scenario of that line:
                    #  - either it will be a next iteration in a loop 
                    #  - it should be an exiter from a normal block to the next lines
                    #  - or it can be a loop that misses an outer next node after the loop completion
                

                # finding the parent container id whether it's a loop or a condition
                # last_block_id = self._GetBranchesParent(id, self._indentation_value[id] - self.uniform_indentation_value, parent_allowed_types=[LineType.Loop, LineType.Condition])
                last_block_id = self._block_id[id]

                if last_block_id != None and self._line_type[last_block_id] == LineType.Loop:
                    self.graph.AddEdge(id, last_block_id, 'NEXT ITERATION', color='#17AFAF')
                else:
                    found = False
                    valid_indentation = self._indentation_value[id]

                    for next_line in range(id + 1, self.graph.Size() - 2):
                       
                        valid_indentation = min(valid_indentation, self._indentation_value[next_line])
                     
                        if self._indentation_value[next_line] <= valid_indentation and not (self._line_type[next_line] == LineType.Condition and self._existing_condition_keyword[next_line] in ['else if', 'else']):
                            found = True
                            
                            last_loop_id = -1

                            if self._line_type[id] == LineType.Loop:
                                last_loop_id = self._last_loop[id - 1] if id - 1 > 0 else -1
                            else:
                                last_loop_id = self._last_loop[id] if id > 0 else -1

                            # either the next line out from loop or it's a next iteration
                            if last_loop_id != -1 and self._indentation_value[last_loop_id] >= self._indentation_value[next_line]:
                                self.graph.AddEdge(id, last_loop_id, 'NEXT ITERATION', color='#17AFAF')
                            else:
                                weight_value = 'BACK TO'
                                font_color = 'black'

                                if self._line_type[id] == LineType.Loop:
                                    weight_value = 'OUT'
                                elif self._line_type[id] == LineType.Condition:
                                    weight_value = 'FALSE'
                                    font_color = 'red'
                                self.graph.AddEdge(id, next_line, weight_value, font_color=font_color)
                            break
                    if not found:
                        if self._last_loop[id] != -1 and id != self._last_loop[id]:
                            self.graph.AddEdge(id, self._last_loop[id], 'NEXT ITERATION', color='#17AFAF')
                        else:
                            self.graph.AddEdge(id, -1,'BACK TO')

        # if there a procedural line after the finishing of the parent loop it would have been dealt with.
        if self._linking_requests.Size() > 0:
            for node_id in self._linking_requests.GetNodes(0):
                last_possible_parent_loop = self._last_loop[self._last_loop[node_id] - 1]
                if last_possible_parent_loop != -1 and self._GetIndentationValueOfLine(last_possible_parent_loop) < self._GetIndentationValueOfLine(self._last_loop[node_id]):
                    self.graph.AddEdge(node_id, last_possible_parent_loop,weight_value='NEXT ITERATION', color="#17AFAF")
                else:
                    self.graph.AddEdge(node_id, -1)



    def _Process(self):
        line_number = 0

        # for debugging
        # for line_of_code in self.lines_of_code:
        #     print((line_of_code))


        for index, line_of_code in enumerate(self.lines_of_code):


            current_indentation = (len(line_of_code) - len(line_of_code.lstrip())) * ' '

            query = line_of_code.strip()
            cleared_query = helpers.ClearStrings(query)
            comment_index = cleared_query.find('//')

            if comment_index != -1:
                self.lines_of_code[index] = current_indentation + cleared_query[:comment_index]

            if 'else' == query[:4] and not 'else if' == query[:7] and len(query) > 4:
                self.lines_of_code.insert(index + 1, '{')
                self.lines_of_code.insert(index + 2, query[4:])
                self.lines_of_code.insert(index + 3, '}')
                self.lines_of_code[index] = 'else'
       

        # # for debugging
        # for line_of_code in self.lines_of_code:
        #     print((line_of_code))

    

        for line_of_code in self.lines_of_code:
            if(self._PreProcessLine(line_of_code.strip())):
                if self.splitting_point and '{' not in helpers.ClearStrings(line_of_code.strip()):
                    self._ProcessLine(line_number, '{')
                    line_number += self._ProcessLine(line_number, line_of_code)
                    self._ProcessLine(line_number, '}')
                else:
                    line_number += self._ProcessLine(line_number, line_of_code)

        if(line_number == 0): line_number = -1

        # self.graph.AddEdge(line_number - 1, -1)
        if self.programming_language == ProgrammingLanguages.CPP:
            with open("formatted_CPP_code.cpp", "w") as file:
                for line in self.processed_lines:
                    file.write(line + '\n')
        elif self.programming_language == ProgrammingLanguages.JAVA:
            with open("formatted_Java_code.java", "w") as file:
                for line in self.processed_lines:
                    file.write(line + '\n')
        elif self.programming_language == ProgrammingLanguages.JavaScript:
            with open("formatted_JavaScript_code.js", "w") as file:
                for line in self.processed_lines:
                    file.write(line + '\n') 