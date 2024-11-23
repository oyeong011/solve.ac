#include<bits/stdc++.h>
using namespace std;
int n, m, ret, mp[100004], mid, lo = 0, hi, mxCp;
bool check(int cp) {
    if (cp < mxCp) return false;
    int tmp = 0, cnt = 1;
    for (int i = 0; i < n; i++) {
        if (tmp + mp[i] > cp) {
            tmp = mp[i];
            cnt++;
        } else {
            tmp += mp[i];
        }
    }
    return cnt <= m;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> mp[i];
        mxCp = max(mxCp, mp[i]);
        hi += mp[i];
    }

    ret = hi;

    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (check(mid)) {
            ret = mid;
            hi = mid - 1;
        }else lo = mid + 1;
    }


    cout << ret << '\n';
}