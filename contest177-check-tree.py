class Solution:
    def DFS(self, visited, exploring, node, left, right):
        visited[node] = 1
        exploring[node] = 1
        #print("visiting node {0}".format(node))
        if left[node] != -1:
            if visited[left[node]] == 1 or exploring[left[node]] == 1:
                return False
            x = self.DFS(visited, exploring, left[node], left, right)
            if x == False:
                return False
        
        if right[node] != -1:
            if visited[right[node]] == 1 or exploring[right[node]] == 1:
                return False
            x = self.DFS(visited, exploring, right[node], left, right)
            if x == False:
                return False
        
        exploring[node] = 0
        return True
        
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        visited = [0 for _ in range(n)]
        exploring = [0 for _ in range(n)]
        component = 0
        
        for i in range(n):
            if visited[i] == 0:
                if component > 0:
                     return False
                x =  self.DFS(visited, exploring, i, leftChild, rightChild)
                if x == False:
                    return False
                component+=1
        return True
