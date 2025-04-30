from concurrent.futures import ProcessPoolExecutor, ThreadPoolExecutor
from functools import partial
import pdb
import threading
import concurrent
from graphviz import Digraph
from collections import deque
from Enums import LineType
import os
import copy
from concurrent.futures import ProcessPoolExecutor
import multiprocessing as mp
# from urllib.parse import urljoin


class Node:

	def __init__(self,data):
		
		self.data = data
		self.childs = []
		self.weight_values = []


def ProcessBatch(graph, dir_path, batch, format, display_graph_fn):
    """Worker function for multiprocessing"""
    for frame in batch:
        graph_copy = graph.copy()  # Avoid modifying the original graph

        graph_copy.node(
            name=frame,
            style="filled",
            fillcolor="#373A40",
            penwidth="3",
            fontcolor="white",
            fontsize="30px",
            fontname="sans-serif",
            # width="1.3",
            # height="1.3"
        )

        display_graph_fn(graph_copy, dir_path, frame, format)  # Call the passed method


class Graph:

	def __init__(self, is_directed = True):
		self.__is_directed = is_directed 
		
		# Key: Identifier (in our case the line number - 1)
		# Value: the line of code content
		self.nodes = {}

		self.nodes_meta_data = {}
		self.__graph = Digraph()
		self.__graph.attr(rankdir='LR')


	def DisplayGraph(self, graph = None, path = "", appendix='',format=None):
		if graph == None:
			graph = self.__graph

		file1_path = os.path.join(path, f'flow-chart-LR{appendix}')
		file2_path = os.path.join(path, f'flow-chart-TB{appendix}')
		
		if not os.path.exists(file1_path) and (format == None or format == 'LR'):
			graph.attr(rankdir='LR')
			graph.render(file1_path, format='png', cleanup=True)

		if not os.path.exists(file2_path) and (format == None or format == 'TB'):
			graph.attr(rankdir='TB')
			graph.render(file2_path, format='png', cleanup=True)

					
	def GetFlows(self,line_type ,root = None):
		
		if root == None:
			root = '-2'

		visited_nodes = {}
		dp = {}
		framesDp = {}
		frames = []

		def DFS(node, weight_value):
			node = int(node)

			if node == 69:
				pass

			if node == -1:
				dp[-1] = "END"
				framesDp[-1] = -1
				return ["END"], [-1]

			if line_type[node] == LineType.Loop and node not in visited_nodes:
				visited_nodes[node] = 1
				for i, child_identifier in enumerate(self.GetNode(node).childs):
					if self.GetNode(node).weight_values[i] == 'BODY':
						current_node_data = f"{self.GetNode(node).data}"

						paths, frames = DFS(child_identifier, 'BODY')
						all_possible_paths = [current_node_data + ' -----> ' + path for path in paths]
						all_possible_frames = [f"{node} {frame}" for frame in frames]
						
						if len(all_possible_paths) == 0:
							all_possible_paths = [current_node_data]
							all_possible_frames = [node]

						dp[node] = all_possible_paths
						framesDp[node] = all_possible_frames
						return dp[node], framesDp[node]

			elif line_type[node] == LineType.Loop and node in visited_nodes and visited_nodes[node] == 1 and weight_value == 'NEXT ITERATION':
				visited_nodes[node] += 1
				for i, child_identifier in enumerate(self.GetNode(node).childs):
					current_node_weight_value = self.GetNode(node).weight_values[i]
					if current_node_weight_value in ['OUT','NEXT ITERATION']:
						dp[node], framesDp[node] = DFS(child_identifier, current_node_weight_value)
						return dp[node], framesDp[node]

			else:
				if node not in dp:
					# print(self.GetNode(node).data)
					visited_nodes[node] = 1

					current_node_data = f" {self.GetNode(node).data}"

					all_possible_paths = []
					all_possible_frames = []

					for i, child_identifier in enumerate(self.GetNode(node).childs):
						
						childs = DFS(child_identifier, self.GetNode(node).weight_values[i])

						if childs != None:
							for path in childs[0]:
								all_possible_paths.append(current_node_data + ' -----> ' + path)
							for frame in childs[1]:
								all_possible_frames.append(f"{node} {frame}")

					if len(all_possible_paths) == 0:
						all_possible_paths = [current_node_data]
						all_possible_frames = [node]

					dp[node] = all_possible_paths
					framesDp[node] = all_possible_frames
				return dp[node], framesDp[node]
				
		paths, frames = DFS(root, '')
		# print(frames)
		newFrames = []
		for frame in frames:
			newFrames.append(frame.split(' '))
		# print(newFrames)

		return paths, newFrames
				
	def Size(self): return len(self.nodes)

	def ExportGraph(self, line_type, path="", get_frames=False, format=None):
		paths, frames = self.GetFlows(line_type)

		# pdb.set_trace()
		# Save the paths
		with open(os.path.join(path, "flow-chart.txt"), "w") as f:
			f.writelines(f"{item}\n" for item in paths)

		if not get_frames:
			return

		dir_path = os.path.join(path, 'frames/')
		os.makedirs(dir_path, exist_ok=True)

		# Get the unique frames =====================================
		uniques = {frame for frame_set in frames for frame in frame_set}
		uniques = list(uniques)

		# Define multiprocessing parameters
		processes_count = min(os.cpu_count() or 4, len(uniques))  # Ensure not more processes than tasks
		batch_size = len(uniques) // processes_count
		processes = []

		# Spawn processes
		for i in range(processes_count):
			batch = uniques[i * batch_size:(i + 1) * batch_size]
			process = mp.Process(
				target=ProcessBatch, 
				args=(self.__graph, dir_path, batch, format, self.DisplayGraph)
			)
			process.start()
			processes.append(process)

		# Process the remaining batch (if any) in the main process
		remaining_batch = uniques[processes_count * batch_size:]
		if remaining_batch:
			ProcessBatch(self.__graph, dir_path, remaining_batch, format, self.DisplayGraph)

		# Wait for all processes to complete
		for process in processes:
			process.join()

		paths = []
		# print(frames)
		# print("Frames are exported!")
		for frameSet in frames:
			paths.append([])
			for frame in frameSet:
				data = []
				if format == None or format == 'LR':
					data.append(os.path.join(dir_path, f'flow-chart-LR{frame}.png'))
				
				if format == None or format == 'TB':
					data.append(os.path.join(dir_path, f'flow-chart-TB{frame}.png'))

				paths[-1].append(data)

		return paths

					

	
	def AddNode(self, identifier, node, shape = 'rectangle', color = '#DDDDDD', fontcolor = 'black'):

		identifier = str(identifier)

		new_node = None
		if identifier not in self.nodes:
			
			# node: must be on type of str or Node
			if isinstance(node, str):
				self.nodes.update({identifier: Node(data=node)})
			else:
				raise Exception("Wrong Node format, only accepting [string or Node class]")
			
			new_node = self.nodes[identifier]
		else:
			new_node = copy.deepcopy(self.nodes[identifier])
			
		# FOR UI
		self.nodes_meta_data[identifier] = {
			"style":'filled',
			"color":color,
			"penwidth": '3',
			"shape": shape,
			"fontcolor":f'{fontcolor}',
			"fontsize":'25px',
			"fontname":'sans-serif'
		}
		
		self.__graph.node(identifier, label=new_node.data, style='filled', fillcolor=color, penwidth='3', shape = shape, fontcolor=fontcolor, fontsize='25px', fontname='Arial bold')

		return new_node


	def AddEdge(self, identifier1, identifier2, weight_value = '', passive_edge=False,color='black',font_color='black'):
		identifier1 = str(identifier1); identifier2 = str(identifier2)
	
		# if identifier2 == '-1':
		# 	print(self.nodes[identifier1].childs)
		# 	print(self.nodes[identifier1].weight_values)
		# 	print(identifier1)

		if(identifier2 not in self.nodes[identifier1].childs):
			# if(passive_edge):
			# 	self.__graph.edge(identifier1, identifier2, label=weight_value, penwidth='1',color=color, fontcolor=font_color,constraints='false')
			# else:
			self.nodes[identifier1].childs.append(identifier2)
			self.nodes[identifier1].weight_values.append(weight_value)
			self.__graph.edge(identifier1, identifier2, label=weight_value, penwidth='3',color=color, fontcolor=font_color,constraints='false',fontsize='20px',fontname='sans-serif',style='bold')
		
	
	def GetNode(self, identifier): return self.nodes[str(identifier)]

	def GetRoot(self): return self.nodes["-2"] # START


