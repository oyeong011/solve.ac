#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, dp[34][34];
ll go(int h, int w) {
    if (h == 0 && w == 0) return 1;
    ll &ret = dp[h][w];
    if (ret) return ret;
    if (h > 0) ret += go(h - 1, w + 1);
    if (w > 0) ret += go(h, w - 1);
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while (1) {
        cin >> n;
        if (n == 0) return 0;
        cout << go(n, 0) << '\n';
    }


}