import sys

N = int(sys.stdin.readline())
expression = sys.stdin.readline().rstrip()

numList = []

for _ in range(N):
    numList.append(int(sys.stdin.readline()))

stack = []

for i in expression:
    if i.isalpha():
        stack.append(numList[ord(i) - ord('A')])
    else:
        b = stack.pop()
        a = stack.pop()
        if i == '+':
            stack.append(a + b)
        elif i == '-':
            stack.append(a - b)
        elif i == '*':
            stack.append(a * b)
        elif i == '/':
            stack.append(a / b)

print(f'{stack[0]:.2f}')