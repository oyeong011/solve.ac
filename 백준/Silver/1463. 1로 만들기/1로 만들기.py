n = int(input())

dp = {1: 0, 2: 1}

def ans(n):
    if n in dp:
        return dp[n]

    if n % 3 == 0 and n % 2 == 0:
        dp[n] = min(ans(n//3), ans(n//2)) + 1
    elif n % 3 == 0:
        dp[n] = min(ans(n//3), ans(n-1)) + 1
    elif n % 2 == 0:
        dp[n] = min(ans(n//2), ans(n-1)) + 1
    else:
        dp[n] = ans(n-1) + 1

    return dp[n]

print(ans(n))