# class TreeNode():
#    def __init__(self, val=None, left_ptr=None, right_ptr=None):
#        self.val = val
#        self.left_ptr = left_ptr
#        self.right_ptr = right_ptr

# complete the function below

def postorderTraversal(root):
    
    if root is None:
        return []
    
    stack = list()
    postorder = list()
    processed = False
    
    stack.append(root)
    while len(stack) != 0:
        node = stack[len(stack)-1]
        if (node == None):
            processed = True
            stack.pop(len(stack)-1)
        
        node = stack.pop(len(stack)-1)
        if processed == True:
            postorder.append(node.val)
            processed = False
        else:
            stack.append(node)
            stack.append(None)
            if (node.right_ptr != None):
                stack.append(node.right_ptr)
            if (node.left_ptr != None):
                stack.append(node.left_ptr)
    
    return postorder
            
    
