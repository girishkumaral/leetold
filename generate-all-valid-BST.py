# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None





class Solution:
    
    def generateHelper(self, i: int, j: int) -> List[TreeNode]:
        R=[]
        #print(i, j)
        if (i == j):
            p = TreeNode(i)
            return [p]
        if i > j:
            return [None]
        else:
            for x in range(i, j+1):
                l = self.generateHelper(i, x-1)
                r = self.generateHelper(x+1, j)
                #print(l)
                #print(r)
                for a in l:
                    for b in r:
                        p = TreeNode(x)
                        p.left = a
                        p.right = b
                        #print(p)
                        R.append(p)
        return R
    
    def generateTrees(self, n: int) -> List[TreeNode]:
        if (n == 0):
            return []
        
        return self.generateHelper(1, n)
