import sys
from collections import deque

N, K = map(int, sys.stdin.readline().split())

_list = []
q = deque([i for i in range(1, N+1)])

while len(q) != 0:
    q.rotate(-K)
    _list.append(str(q.pop()))
   
print("<", ", ".join(_list), ">", sep="")