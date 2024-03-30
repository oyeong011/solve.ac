import sys
from collections import deque
def input():
    return sys.stdin.readline().rstrip()

queue = deque()

num = int(input())
for _ in range(num):
    command = sys.stdin.readline().split()
    op = command[0]

    if op == 'push':
        queue.append(command[1])
    elif op == 'pop':
        print(queue.popleft() if queue else -1)
    elif op == 'size':
        print(len(queue))
    elif op == 'empty':
        print(int(not queue))
    elif op == 'front':
        print(queue[0] if queue else -1)
    elif op == 'back':
        print(queue[-1] if queue else -1)
