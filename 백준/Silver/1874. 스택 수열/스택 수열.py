
cnt = 1
temp = True
stack = []
op = []

N = int(input())
for i in range(N):
    num = int(input())
    while cnt <= num:
        stack.append(cnt)
        op.append('+')
        cnt += 1
    if stack[-1] == num:
        stack.pop()
        op.append('-')
    else:
        temp = False
        break

if temp == False:
    print('NO')
else:
    for i in op:
        print(i)
