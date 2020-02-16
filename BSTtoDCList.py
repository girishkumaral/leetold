def BTtoLL(root):
    
    if root is None:
        return None
        
    if root.left_ptr is None and root.right_ptr is None:
        root.left_ptr = root
        root.right_ptr = root
        return root
    
    elif root.left_ptr is not None and root.right_ptr is None:
        root.right_ptr = BTtoLL(root.left_ptr)
        root.left_ptr = root.right_ptr.left_ptr
        root.right_ptr.left_ptr.right_ptr = root
        root.right_ptr.left_ptr = root
        return root.right_ptr
    elif root.right_ptr is not None and root.left_ptr is None:
        tmp = BTtoLL(root.right_ptr)
        root.left_ptr = tmp.left_ptr
        tmp.left_ptr.right_ptr = root
        tmp.left_ptr = root
        root.right_ptr = tmp
        return root
    else:
        tmp1 = BTtoLL(root.left_ptr)
        tmp2 = BTtoLL(root.right_ptr)
        root.left_ptr = tmp1.left_ptr
        root.right_ptr = tmp2
        tmp1.left_ptr.right_ptr = root
        tmp1.left_ptr = tmp2.left_ptr
        tmp2.left_ptr.right_ptr = tmp1
        tmp2.left_ptr = root
        return tmp1
