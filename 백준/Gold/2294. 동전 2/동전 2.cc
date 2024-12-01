#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, k, ret, a, dp[10004];
vector<int> v;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    fill(dp, dp + 10004, INF);

    dp[0] = 0;
    for (auto coin : v) {
        for (int i = coin; i <= k; i++) {
            if (dp[i - coin] != INF) dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    if (dp[k] != INF)cout << dp[k] << '\n';
    else cout << -1 << '\n';
}