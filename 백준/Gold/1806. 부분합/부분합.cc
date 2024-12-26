//
// Created by 권오영 on 24. 12. 26.
//
#include<bits/stdc++.h>
using namespace std;
int n, s, a[100004], l, r, ret = 1e9;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    if (s > a[n]) {
        cout << 0 << "\n";
        return 0;
    }

    l = n - 1, r = n;
    while (l < r && l >= 0) {
        int sum = a[r] - a[l];
        if (sum >= s) {
            ret = min(ret, r - l);
            r--;
        } else {
            l--;
        }
    }
    cout << ret << "\n";
}