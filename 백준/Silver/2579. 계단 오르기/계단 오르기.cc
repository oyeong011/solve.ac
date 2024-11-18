#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int stairs[301] = {0,};
    for(int i = 1; i <= n; i++) {
        cin >> stairs[i];
    }

    int dp[301][3] = {0,};
    dp[1][1] = stairs[1];

    for(int i = 2; i <= n; i++) {
        dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + stairs[i];
        dp[i][2] = dp[i-1][1] + stairs[i];
    }

    cout << max(dp[n][1], dp[n][2]) << '\n';

    return 0;
}