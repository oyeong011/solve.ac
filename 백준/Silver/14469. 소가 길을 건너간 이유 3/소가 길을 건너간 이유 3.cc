#include<bits/stdc++.h>
using namespace std;
int n, ret;
vector<pair<int, int>> v;
int main() {
    ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (ret < v[i].first) {
            ret = v[i].first;
            ret += v[i].second;
        }else if (ret >= v[i].first) {
            ret += v[i].second;
        }
    }

    cout << ret << '\n';
}