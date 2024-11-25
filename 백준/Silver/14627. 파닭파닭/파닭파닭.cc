#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s, c, a, lo = 1, hi = 1e9, ret, sum, co;
vector<ll> pa;
bool check(ll num) {
    ll cnt = 0;
    for (auto c : pa) {
        cnt += c / num;
    }
    return cnt >= c;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s >> c;
    for (int i = 0; i < s; i++) {
        cin >> a; pa.push_back(a);
        sum += a;
    }

    while (lo <= hi) {
        ll mid = (lo + hi) / (2 * 1LL);
        if (check(mid)) {
            lo = mid + 1;
            ret = mid;
        } else {
            hi = mid - 1;
        }
    }

    cout << sum - ret * c << '\n';
}