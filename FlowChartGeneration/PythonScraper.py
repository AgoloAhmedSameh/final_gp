from Graph import Graph, Node
from collections import deque
from RQueue import RQueue
from Enums import LineType
from Formater import Formater
import helpers


from Scraper import Scraper
class PythonScraper(Scraper):
	"""
	Scraping python files to create the needed nodes to generate a flowchart
	"""

	def __init__(self, code:str, uniform_indentation_value:int = 4, export_path = "", get_frames=False, output_format=None):
		super().__init__(Formater.Python(code))

		
		self.uniform_indentation_value = uniform_indentation_value

	
		# python meta data vars: =============================================
		self._loop_keywords = ['do','while','for']
		self._splitting_keywords = ['elif','if','else']

		self._last_loop_keyword = None
		# ====================================================================

		self._indentation_value[-2] = self._indentation_value[-1] = 0

		self._Process() # Calls _PreProcessLine
		self._PostProcess()
		
		self.simulation_paths = self.graph.ExportGraph(self._line_type, path=export_path, get_frames=get_frames, format=output_format)
		self.graph.DisplayGraph(path=export_path)



	def _ProcessLine(self, line_number, line_of_code:str):
	
		current_indentation_value = len(line_of_code) - len(line_of_code.lstrip(' '))
		current_line_type = None
		self._indentation_value[line_number] = current_indentation_value

		if line_number > 0 and current_indentation_value > self._indentation_value[line_number - 1]:
			self._stack_of_blocks.append(line_number - 1)
		elif line_number > 0 and current_indentation_value < self._indentation_value[line_number - 1]:
			
			blocks_count = (self._indentation_value[line_number - 1] - current_indentation_value) // self.uniform_indentation_value
			for i in range(blocks_count):
				self._stack_of_blocks.pop()

		if len(self._stack_of_blocks) > 0:
			self._block_id[line_number] = self._stack_of_blocks[-1]
		else:
			self._block_id[line_number] = None

		# Console Debugging:
        # print(f"line number = {line_number}", f"current_block = {self._block_id[line_number]}", f"current_indentation_value = {current_indentation_value}", "\t\t\t", line_of_code, '\n')

		# ============================ Initializing the current Node =============================
		self.graph.AddNode(line_number, line_of_code.strip())
		if line_number == 0:
			self.graph.AddEdge(-2, line_number)
		# ============================ Initializing the current Node =============================

		last_loop_index = self._FindLoopIndex(line_of_code.strip())
		last_Condition_index = self._FindConditionIndex(line_of_code.strip())
		query_string = helpers.ClearStrings(line_of_code.lower())

		if(
			current_indentation_value < self._indentation_value[line_number - 1] 
			and (
				len(self._stack_of_loops_indentation_value) > 0 and current_indentation_value <= self._stack_of_loops_indentation_value[-1] 
			)
		):

			for node_id in self._linking_requests.GetNodes(current_indentation_value):
				last_possible_parent_loop = self._last_loop[self._last_loop[node_id] - 1]
				if last_possible_parent_loop != -1 and self._GetIndentationValueOfLine(last_possible_parent_loop) < self._GetIndentationValueOfLine(self._last_loop[node_id]):
					self.graph.AddEdge(node_id, last_possible_parent_loop,weight_value='NEXT ITERATION', color="#17AFAF")
				else:
					self.graph.AddEdge(node_id, line_number)

			self._linking_requests.Pop(current_indentation_value)

			while(len(self._stack_of_loops) > 0 and current_indentation_value <= self._stack_of_loops_indentation_value[-1]):
				self._stack_of_loops.pop()
				self._stack_of_loops_indentation_value.pop()

		# check the type of the current line to scrap info for the required edges related to this node
		if(last_loop_index == 0):
			self._stack_of_loops.append(line_number)
			current_line_type = LineType.Loop
			self._stack_of_loops_indentation_value.append(current_indentation_value)


		elif (last_Condition_index == 0):
			current_line_type = LineType.Condition
			for condition_keyword in self._splitting_keywords:
				if condition_keyword in query_string:
					self._existing_condition_keyword[line_number] = condition_keyword
					break
		else:
			if 'continue' in query_string:
				self.graph.AddEdge(line_number, self._stack_of_loops[-1], weight_value='NEXT ITERATION', color='#17AFAF')
				current_line_type = LineType.TerminatorOfLoop
			elif 'break' in query_string:
				parent_line_number = self._block_id[line_number]
				parent_block_type = self._line_type[parent_line_number]

				while parent_block_type != LineType.Loop:
					parent_line_number = self._block_id[parent_line_number]
					parent_block_type = self._line_type[parent_line_number]

				self._linking_requests.Push(line_number, self._GetIndentationValueOfLine(parent_line_number))
				current_line_type = LineType.TerminatorOfLoop
			elif 'return' in query_string:
				current_line_type = LineType.TerminatorOfProgram			
				self.graph.AddEdge(line_number, -1)
			elif 'yield' in query_string:
				current_line_type = LineType.TerminatorOfProgram
				self.graph.AddEdge(line_number, -1)
			else:
				current_line_type = LineType.Procedural
			
		self._line_type[line_number] = current_line_type
		
		node_color = '#eeeeee'
		node_shape = 'rectangle'
		font_color = 'black'

		if current_line_type == LineType.Condition:
			node_color =  '#17AFAF' # 'darkkhaki'
			node_shape = 'diamond'
			font_color = 'white'
		elif current_line_type == LineType.Loop:
			node_color = '#17AFAF'
			node_shape = 'rarrow'
			font_color = 'white'
		
		self.graph.AddNode(line_number, line_of_code.strip(), node_shape, color=node_color,fontcolor=font_color)

		# Not a Terminator
		parent_allowed_types = [LineType.Procedural, LineType.Loop, LineType.Condition]
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

		prev_node_code = self.graph.nodes[str(prev_node_id)].data

		if not (
			prev_node_code[:4].strip() == 'else' and weight_value == 'FALSE'
			or
			len(self.graph.nodes[str(prev_node_id)].childs) == 1 and self._line_type[prev_node_id] == LineType.Procedural
		):
			self.graph.AddEdge(prev_node_id, line_number, weight_value, font_color=font_color)

		if len(self._stack_of_loops) > 0:
			self._last_loop[line_number] = self._stack_of_loops[-1]
		else:
			self._last_loop[line_number] = -1
			

	def _PreProcessLine(self, line_of_code):
		if(len(line_of_code) == 0):
			return False
		
		if(line_of_code.find('*/') != -1 and self.multi_line_commnet):
			self.multi_line_commnet = False
		if(line_of_code.find('/*') != -1):
			self.multi_line_commnet = True
			return False
		
		# comment or a decorator
		if(helpers.ClearStrings(line_of_code.lower())[0] in ['#',' @']):
			return False
		return True
	
	def _PostProcess(self):
		for id in range(self.graph.Size() - 2): # not counting the start and the end nodes
			current_node = self.graph.GetNode(id)
			line_type = self._GetLineType(id)

			# 1 - check if it's problematic line:
				# problematic line if the current line:
				#  1 - not a terminator
				#  2 - it's a leaf node or a condition or a loop that is missing a branch except for else


			if line_type not in [LineType.TerminatorOfLoop, LineType.TerminatorOfProgram] and (
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

						if self._indentation_value[next_line] <= valid_indentation and not (self._line_type[next_line] == LineType.Condition and self._existing_condition_keyword[next_line] in ['elif', 'else']):
							found = True
							


							if self._line_type[id] == LineType.Loop:
								last_loop_id = self._last_loop[id - 1] if id - 1 > 0 else -1
							else:
								last_loop_id = self._last_loop[id] if id > 0 else -1
							
							# either the next line out from loop or it's a next
							if last_loop_id != -1 and self._indentation_value[last_loop_id] >= self._indentation_value[next_line]:
								self.graph.AddEdge(id, last_loop_id,'NEXT ITERATION', color='#17AFAF')
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
							self.graph.AddEdge(id, -1,'back to')

		if self._linking_requests.Size() > 0:
			for node_id in self._linking_requests.GetNodes(0):
				last_possible_parent_loop = self._last_loop[self._last_loop[node_id] - 1]
				if last_possible_parent_loop != -1 and self._GetIndentationValueOfLine(last_possible_parent_loop) < self._GetIndentationValueOfLine(self._last_loop[node_id]):
					self.graph.AddEdge(node_id, last_possible_parent_loop,weight_value='NEXT ITERATION', color="#17AFAF")
				else:
					self.graph.AddEdge(node_id, -1)



	def _Process(self):

		

		line_number = 0 # START if there's no code


		for index, line_of_code in enumerate(self.lines_of_code):

			query = line_of_code.strip()

			cleared_query = helpers.ClearStrings(query)
			comment_index = cleared_query.find('#')

			if comment_index != -1:
				self.lines_of_code[index] = line_of_code[:comment_index]

		# for debugging
        # for line_of_code in self.lines_of_code:
            # print((line_of_code))

		for line_of_code in self.lines_of_code:

			# if there's like a SQL query in a str it will result for a conflict!
			if(self._PreProcessLine(line_of_code.strip())):
				self._ProcessLine(line_number, line_of_code)
				line_number += 1

		if(line_number == 0): line_number = -1
		# self.graph.AddEdge(line_number - 1, -1)

		# print(self._block_id.values())
		# print(self._last_loop)
		# print(self._existing_condition_keyword)
		# print(self.graph.nodes.keys())
		# for node in self.graph.nodes.values():
			
		# 	print(node.data)
		# print(self._indentation_value)
