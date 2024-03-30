
import sys

num = int(sys.stdin.readline())

for _ in range(num):
    testcase = input()
    cnt = 0
    for c in testcase:
        cnt += 1 if c == '(' else -1
        if cnt < 0:
            result = 'NO'
            break
        else:
            result = 'YES' if cnt == 0 else 'NO'
    print(result)