#include<bits/stdc++.h>
using namespace std;
int from, to, n, idx = 0, ret = 1;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++) {
        cin >> from >> to;
        v.push_back(make_pair(to, from));
    }
    sort(v.begin(), v.end());
    to = v[0].first;
    for (int i = 1; i < n; i++) {
        if (v[i].second < to) continue;
        to = v[i].first; ret++;
    }
    cout << ret << "\n";
}