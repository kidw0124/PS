class Node:
    def __init__(self, key, value, left=None, right=None):
        self.key = key
        self.value = value
        self.left = left
        self.right = right


class BST:
    def __init__(self):
        self.root = None

    def find(self, k):
        return BST.find_element(self.root, k)

    def insert(self, key, val):
        if self.root == None:
            self.root = Node(key, val)
        else:
            BST.insert_element(self.root, key, val)

    def insert_element(node, key, val):
        if node.key == key:
            node.value.append(val)
        elif node.key < key:
            next = node.right
            if next == None:
                node.right = Node(key, val)
            else:
                BST.insert_element(next, key, val)
        else:
            next = node.left
            if next == None:
                node.left = Node(key, val)
            else:
                BST.insert_element(next, key, val)

    def find_element(node, k):
        if node == None:
            return None
        elif node.key == k:
            return node.value
        elif node.key < k:
            return BST.find_element(node.right, k)
        else:
            return BST.find_element(node.left, k)

bst = BST()

for _ in range(28):
    bst.insert(int(input()),'')

for i in range(1,31):
    if bst.find(i) == None:
        print(i)
