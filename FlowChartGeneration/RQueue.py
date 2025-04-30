class RQueue: # stand for Requests Queue!
    def __init__(self) -> None:
        self.__queue = {}

    def Size(self) -> int:
        return len(self.__queue)

    def Push(self, node_id: int, destination_indentation_value: int) -> None:
        # ensuring that the parameters are of type int
        if not isinstance(destination_indentation_value, int):
            Exception("destination_indentation_value: should be Int")
        if not isinstance(node_id, int):
            Exception("node_id: should be Int")
        
        self.__queue.update({node_id: destination_indentation_value})

    def Pop(self, indentation_value) -> None:
        """
            pops from the queue all the nodes that correspond to this indentation_value or less
        """
        keys_to_be_removed = []

        for node_id in self.__queue:
            if self.__queue[node_id] >= indentation_value:
                keys_to_be_removed.append(node_id)
        
        for key in keys_to_be_removed:
            del self.__queue[key]
    
    def GetNodes(self, indentation_value, get_all_nested=True) -> list[int]:
        """
            returns a list of nodes that correspond to this indentation_value
        """

        nodes = []

        for node_id in self.__queue:
            if self.__queue[node_id] == indentation_value:
                nodes.append(node_id)
            elif get_all_nested and self.__queue[node_id] > indentation_value:
                nodes.append(node_id)
        
        return nodes
    
    def Clear(self): self.__queue.clear()

    def DisplayLinks(self):
        temp_dic = {}

        for node_id in self.__queue:
            dst_val = self.__queue[node_id]
            if dst_val in temp_dic:
                temp_dic[dst_val].append(node_id)
            else:
                temp_dic.update({dst_val: [node_id]})

        for indentation_value in sorted(temp_dic):
            print(f"At indentation level: {indentation_value} \n")
            print(f'\t{temp_dic[indentation_value]}')

    def DisplayQueue(self):
        print(self.__queue)

        

# q = RQueue()

# q.Push(3, 1)
# q.Push(3, 4)
# q.Push(2, 1)
# q.Push(9, 3)
# q.Push(9, 4)

# q.DisplayQueue()
# q.DisplayLinks()
# print(20 * '=')
# q.Pop(3)

# q.DisplayQueue()
# q.DisplayLinks()
# print(20 * '=')

# q.Pop(9)
# q.DisplayQueue()
# q.DisplayLinks()
# print(20 * '=')


