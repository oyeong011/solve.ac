from collections import deque


n = int(input())
list = list(map(int, input().split()))

deq = deque(list)
num = deque([i for i in range(1, n + 1)])
result = []

for _ in range(len(list)):
    result.append(num.popleft())
    move = deq.popleft()
    if move > 0:
        deq.rotate(-move + 1)
        num.rotate(-move + 1)
    else:
        deq.rotate(-move)
        num.rotate(-move)

print(*result)