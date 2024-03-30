import sys

num = int(sys.stdin.readline())  # O(1)
stack = []  # O(1)

for _ in range(num):  # O(num)
    command = sys.stdin.readline().split()  # O(1)
    op = command[0]  # O(1)

    if op == 'push':
        stack.append(command[1])  # O(1)
    elif op == 'pop':
        print(stack.pop() if stack else -1)  # O(1)
    elif op == 'size':
        print(len(stack))  # O(1)
    elif op == 'empty':
        print(int(not stack))  # O(1)
    elif op == 'top':
        print(stack[-1] if stack else -1)  # O(1)