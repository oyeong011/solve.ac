import sys
input = sys.stdin.readline

stack = []

n = int(input().strip())

for _ in range(n):
    cmd = input().strip().split()

    if cmd[0] == "push":
        stack.append(int(cmd[1]))
    elif cmd[0] == "pop":
        if stack:
            print(stack.pop())
        else:
            print(-1)
    elif cmd[0] == "size":
        print(len(stack))
    elif cmd[0] == "empty":
        print(0 if stack else 1)
    elif cmd[0] == "top":
        if stack:
            print(stack[-1])
        else:
            print(-1)