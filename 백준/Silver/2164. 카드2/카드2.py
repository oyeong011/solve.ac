N, a = int(input()) , 1

while N > a:
    a *= 2

print((N-(a//2))*2 if N != 1 else 1)