#include<bits/stdc++.h>
using namespace std;
int n, dp[100004], c, m1, m2;
int main() {
    while (1) {
        scanf("%d %d.%d", &n, &m1, &m2);
        if (n == 0)return 0;

        memset(dp, 0, sizeof(dp));
        int totalP = m1 * 100 + m2;

        for (int i = 0; i < n; i++) {
            scanf("%d %d.%d", &c, &m1, &m2);
            int price = m1 * 100 + m2;
            for (int j = price; j <= totalP; j++) {
                dp[j] = max(dp[j], dp[j - price] + c);
            }
        }
        printf("%d\n", dp[totalP]);
    }
    return 0;
}