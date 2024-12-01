#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, k, ret, a, dp[10004];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    fill(dp, dp + 10004, INF);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> a;
        for (int j = a; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - a] + 1);
        }
    }


    if (dp[k] != INF)cout << dp[k] << '\n';
    else cout << -1 << '\n';
}