#include <bits/stdc++.h>
using namespace std;
int n, m, mid, ret = 1e9;
vector<int> v;

bool go(int val) {
    int cnt = 0;
    for (int a: v) {
        cnt += a / val;
        if (a % val)cnt++;
    }
    return cnt <= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int left = 1, right = 0;
    for (int i = 1; i <= m; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        right = max(right, a);
    }
    while (left <= right) {
        mid = (left + right) / 2;
        if (go(mid)) {
            ret = min(ret, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ret << '\n';
}
