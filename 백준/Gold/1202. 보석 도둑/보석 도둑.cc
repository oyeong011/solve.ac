#include<bits/stdc++.h>
using namespace std;
int n, k;
typedef long long ll;
ll ret;
vector<pair<ll,ll>> v;
vector<ll> bag;
int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    for (int i = 0 ; i < k; i++) {
        int a; cin >> a;
        bag.push_back(a);
    }
    sort(v.begin(), v.end());
    sort(bag.begin(), bag.end());
    priority_queue<ll> pq;

    int j = 0;
    for (auto c : bag) {
        while (j < n && v[j].first <= c) pq.push(v[j++].second);
        if (!pq.empty()) {
            ret += pq.top(); pq.pop();
        }
    }
    cout << ret << "\n";
}