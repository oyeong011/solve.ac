#include<bits/stdc++.h>
using namespace std;
int n, m, idx, ret, b;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(),v.end());
    for (int i = 0; i < n; i++) {
        if (v[i].second <= idx) continue;
        if (idx < v[i].first) {
            b = (v[i].second - v[i].first) / m + ((v[i].second - v[i].first) % m ? 1 : 0);
            idx = v[i].first + b * m;
        } else {
            b = (v[i].second - idx) / m + ((v[i].second - idx) % m ? 1 : 0);
            idx = idx + b * m;
        }
        ret += b;
    }

    cout << ret;
    return 0;
}