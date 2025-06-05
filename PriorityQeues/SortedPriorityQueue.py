
# composition design pattern
'''
    For example, a university owns various departments (e.g., chemistry),
    and each department has a number of professors. If the university closes,
    the departments will no longer exist, but the professors in those departments will continue to exist.
    Therefore, a University can be seen as a composition of departments, whereas departments have an aggregation of professors.
    In addition, a Professor could work in more than one department,
    but a department could not be part of more than one university.
'''
from queue import Empty

'''
    build priority queue based on single linked list
    ==== operations ======
    - push -> O(N)
    - pop -> O(1) 
    - peek -> O(1)
    - isEmpty -> O(1)
    - len -> (1)
'''


class PriorityQueueNode:
    def __init__(self, value, priority):
        self.value = value
        self.priority = priority
        self.next = None


class PriorityQueue:
    def __init__(self):
        self.head = None
        self.length = 0

    def isEmpty(self):
        return self.head is None

    def __len__(self):
        return self.length

    def push(self , value , priority):
        node = PriorityQueueNode(value , priority)

        if self.isEmpty():
            self.head = node
        else:
            curr = self.head
            while curr.next:
                if curr.next.priority > priority:
                    break
                curr = curr.next
            node.next = curr.next
            curr.next = node

    def pop(self) -> PriorityQueueNode:
        if self.isEmpty():
            raise Empty("the PQ is empty")
        else:
            result = self.head
            self.head = self.head.next
        return result

    def peek(self):
        if self.isEmpty():
            raise Empty("the PQ is empty")
        return self.head.value