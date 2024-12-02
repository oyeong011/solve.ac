#include<bits/stdc++.h>
using namespace std;
int L[24], J[24], n, dp[104];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> L[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> J[i];
        for (int j = 100; j > L[i]; j--) {
            dp[j] = max(dp[j], dp[j - L[i]] + J[i]);
        }
    }

    cout << dp[100] << '\n';

}