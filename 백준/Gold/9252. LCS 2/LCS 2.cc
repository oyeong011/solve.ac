#include<bits/stdc++.h>
using namespace std;
string s1, s2, ret;
int dp[1004][1004], n, m;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s1 >> s2;
    int n = s1.length(), m = s2.length();


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][m] << "\n";

    if (dp[n][m] == 0) return 0;

    while (n > 0 && m > 0) {
        if (s1[n - 1] == s2[m - 1]) ret = s1[n - 1] + ret, n--, m--;
        else if (dp[n - 1][m] > dp[n][m - 1]) n--;
        else m--;
    }

    cout << ret << "\n";
    return 0;

}