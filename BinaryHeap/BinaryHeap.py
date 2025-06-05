from queue import Empty

class BinaryHeap:
    def __init__(self):
        self.data = []

    def __len__(self):
        return len(self.data)

    def parent(self , j):
        return (j - 1) // 2

    def left(self, j):
        return 2 * j + 1

    def right(self, j):
        return 2 * j + 2

    def has_left(self , j):
        return self.left(j) < len(self.data)

    def has_right(self , j):
        return self.right(j) < len(self.data)

    def swap(self , j, q):
        self.data[j] , self.data[q] = self.data[q] , self.data[j]

    def heapUp(self , child):
        parent = self.parent(child)
        if child > 0 and self.data[parent] > self.data[child]:
            self.swap(child , parent)
            self.heapUp(parent)

    def heapDown(self , node):
        if self.has_left(node):
            left = self.left(node)
            small_child = left
            if self.has_right(node):
                right = self.right(node)
                if self.data[right] < self.data[left]:
                    small_child = right
            if self.data[small_child] < self.data[node]:
                self.swap(small_child , node)
                self.heapDown(small_child)

    def add(self , key):
        self.data.append(key)
        self.heapUp(len(self.data) -1)

    def is_empty(self):
        return len(self.data) == 0

    def min(self):
        if self.is_empty():
            raise Empty('the heap is empty')
        return self.data[0]

    def remove_min(self):
        if self.is_empty():
            raise Empty('the heap is empty')

        self.swap(0 , len(self.data) -1)
        minValue = self.data.pop()
        self.heapDown(0)
        return minValue


