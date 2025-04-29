from typing import List, Tuple
from graph_generator.FunctionNode import FunctionNode
from typing import Dict
from collections import deque

class graph:
    def __init__(self,Nodes:List[FunctionNode]):

        self.Nodes=Nodes
        # key -> str | value the node it self
        self.NodesDict:Dict[str,FunctionNode] = dict()
        
    def construct_Graph(self) -> None:
        #Init Keys
        self.in_degree = {node._Hashed: 0 for node in self.Nodes}

        # init the dict
        for node in self.Nodes:
            if node.get_hashed not in self.NodesDict:
                self.NodesDict[node._Hashed]= node

        print(self.NodesDict)

        #init the in_degree by counting how much each function called   
        for node in self.Nodes:
            for neighbor in node.get_FunctionsCallsInside():
                if neighbor[0] in self.NodesDict:
                    print(neighbor[0])
                    self.in_degree[neighbor[0]] += 1
                    
        for node_id, node in self.NodesDict.items():
          print(f"Function hashed {node_id} calls:", node.get_FunctionsCallsInside())

        self.queue = deque() # queue will contain id for the roots to get the childs from NodesDict

        for node_ID in self.in_degree:
            if self.in_degree[node_ID] == 0:
                self.queue.append(node_ID)

        print(self.in_degree)




    from typing import List, Tuple, Dict

    def Topological_Sort(self) -> Tuple[List[int],  Dict[str, object]]:
     topo_order = []
    
     while self.queue:
        node = self.queue.popleft()
        topo_order.append(self.NodesDict[node])
        
        for neighbor in self.NodesDict[node].get_FunctionsCallsInside():  
            if neighbor[0] in self.NodesDict:
                self.in_degree[neighbor[0]] -= 1
                if self.in_degree[neighbor[0]] == 0:
                    self.queue.append(neighbor[0])
    
     topo_order.reverse()
    
    
     hashed_node_dict = {}

     for node in topo_order:
        hashed_name = node.get_hashed()
        hashed_node_dict[hashed_name] = node  # Store hashed name as key and node as value

    # Returns Nodes Objects, Hashed Name Ordered List, and Dictionary
     return topo_order, hashed_node_dict




#------------------------------------------------------------------------------------------------------#
def dfs(self,Start_Id)->Tuple[List[int],List[str]] :
        visited = set()
        stack = [Start_Id]
        Final_List_ids = []
        Final_List_names = []
        while stack :
            
            st_id = stack.pop()
            if st_id not in visited :
                visited.add(st_id)
                Final_List_ids.append(st_id)
                
                for neighbors in self.NodesDict[st_id].get_FunctionsCallsInside():
                    if neighbors[0] in self.reverse_dict:
                      neighbor_ID=self.reverse_dict[neighbors[0]]
                      if neighbor_ID not in visited:
                       stack.append(neighbor_ID)
                    #   Final_List_ids.append(neighbor_ID)

        for i in Final_List_ids:
            Final_List_names.append(self.NodesDict[i].get_Function_Name())

        return Final_List_ids, Final_List_names


     