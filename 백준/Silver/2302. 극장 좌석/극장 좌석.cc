#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a, temp = 1;
ll dp[44], VIP[44];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cin >> m;
    memset(dp, 1, sizeof(dp));
    memset(VIP, 0, sizeof(VIP));
    dp[0] = 0, dp[1] = 1;
    for (int i = 0; i < m; i++) {
        cin >> a;
        VIP[a + 1] = 1;
        dp[a + 1] = 1;
    }

    for (int i = 2; i <= n + 1; i++) {
        if (VIP[i]) temp *= dp[i - 1], dp[i - 1] = 0;
        else dp[i] = dp[i - 1] + dp[i - 2];
    }

    if (VIP[n + 1]) cout << temp << "\n";
    else cout << dp[n + 1] * temp << "\n";

}

