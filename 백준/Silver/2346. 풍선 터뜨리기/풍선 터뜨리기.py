from collections import deque

n = int(input())
list = list(map(int, input().split()))

deq = deque(enumerate(list))
result = []

for _ in range(len(list)):
    n, move = deq.popleft()
    result.append(n + 1)
    if move > 0:
        deq.rotate(-move + 1)
    else:
        deq.rotate(-move)

print(*result)