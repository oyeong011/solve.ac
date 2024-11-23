#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ret;
ll cur = -1000000001;
vector<pair<ll, ll>> v;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    // for (int i = 0; i < n; i++) {
    //     cout << v[i].first << " " << v[i].second << "\n";
    // }
    for (auto pa : v) {
        if (cur > pa.second) continue;
        if (cur >= pa.first) {
            ret += pa.second - cur;
            cur = pa.second;
        } else {
            ret += pa.second - pa.first;
            cur = pa.second;
        }
        // cout << ret << "\n";

    }

    cout << ret << "\n";

}