from typing import List


class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def insert(root, val):
    if not root:
        return TreeNode(val)
    if root.val > val:
        root.left = insert(root.left, val)
    else:
        root.right = insert(root.right, val)
    return root

def search(root, value):
    if root is None:
        return False
    if value < root.val:
        return search(root.left , value)
    elif value > root.val:
        return search(root.right , value)
    return True
def inorder(root):
    if not root:
        return
    inorder(root.left)
    print(root.val, end=" ")
    inorder(root.right)

result = True

def is_bst(root):
    global result
    if root:
        left = root.left.val if root.left else float('-inf')
        right = root.right.val if root.right else float('inf')

        if not (root.val < right and root.val > left):
            result = False
            return

        is_bst(root.left)
        is_bst(root.right)

def get_middles(arr, start, end, result):
    if start >= end:
        return
    mid = start + (end - start) // 2
    result.append(arr[mid])
    get_middles(arr, start, mid, result)
    get_middles(arr, mid + 1, end, result)

def convert_array_to_bbst(root, arr):
    for val in arr:
        root = insert(root, val)
    return root

def getKthSmallest(root, k, value):
    if not root:
        return
    getKthSmallest(root.left, k, value)
    k[0] -= 1
    if k[0] == -1:
        value[0] = root.val
        return
    getKthSmallest(root.right, k, value)


def minValue(root: TreeNode):
    while root.left:
        root = root.left
    return root

def maxValue(root : TreeNode)->TreeNode:
    while root.right:
        root = root.right
    return root

def getSuccessor(root : TreeNode , target : TreeNode):
    if target.right:
        return minValue(target.right)
    successor = None
    curr = root
    while curr:
        if curr.val > target.val:
            successor = curr
            curr = curr.left
        elif curr.val < target:
            curr = curr.right
        else:
            break
    return successor


def deleteNode(root : TreeNode , value : int) ->TreeNode:
    if not root:
        return root
    if value < root.val:
        root.left = deleteNode(root.left , value)
    elif value > root.val:
        root.right = deleteNode(root.right , value)
    else:
        if not root.left:
            return root.right
        elif not root.right:
            return roo.left
        else:
            curr = root.right
            while curr.left:
                curr = curr.left
            root.val = curr.val 
            root.right = deleteNode(root.right , root.val)

    return root

def main():
    root = TreeNode(1)
    first = 10
    second = None
    mylist = []
    if first and second:
        print(max(first , second))
    else:
        notNone = first if not None else second
        print(notNone)
if __name__ == '__main__':
    main()