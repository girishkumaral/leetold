class cnt:
    count = 0
    val = 0
    def __init__(self):
        self.count = 0
        self.val = 0
        
    def inc(self):
        self.count+=1
    
    def get(self):
        return self.count

    def set(self, val):
        self.val = val
    
    def getval(self):
        return self.val
    
def helper(node, count, k):
    
    if node is None:
        return

    if node.left_ptr is not None:
        helper(node.left_ptr, count, k)
    
    #l.append(node.val)
    count.inc()
    if count.get() == k:
        count.set(node.val)
        return

    if node.right_ptr is not None:
        helper(node.right_ptr, count, k)
    
def kth_smallest_element(root, k):
    count = cnt()
    helper(root, count, k)
    return count.getval()
