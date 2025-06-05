from SortedPriorityQueue import PriorityQueue

def main():
    first = PriorityQueue()
    first.push('a' , 1)
    first.push('b' , 3)
    first.push('c' , 2)

    while not first.isEmpty():
        print(first.pop().value)

if __name__ == '__main__':
    main()


