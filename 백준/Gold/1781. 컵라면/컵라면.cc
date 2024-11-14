#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;
int n, ret;
int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        pq.push(v[i].second);
        if (pq.size() > v[i].first) {
            pq.pop();
        }
    }
    while (!pq.empty()) {
        ret += pq.top(); pq.pop();
    }
    cout << ret;
}