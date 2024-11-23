#include<bits/stdc++.h>
using namespace std;
int n, m, mp[100004], ret, mx, mid, hi, lo = 0;
bool solve(int cash) {
    if (mx > cash)return false;
    int tmp = cash, cnt = 1;
    for (int i = 0; i < n; i++) {
        if (tmp - mp[i] < 0) {
            tmp = cash;
            cnt++;
        }
        tmp -= mp[i];
    }
    return cnt <= m;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> mp[i];
        mx = max(mx, mp[i]);
        hi += mp[i];
    }

    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (solve(mid)) {
            hi = mid - 1;
            ret = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << ret << '\n';
}