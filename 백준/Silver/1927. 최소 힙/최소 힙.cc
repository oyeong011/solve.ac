#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a;
priority_queue<ll, vector<ll>, greater<>> pq;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == 0) {
            if (pq.empty()) {
                cout << 0 << '\n';
                continue;
            }
            cout << pq.top() << "\n";
            pq.pop();
        } else {
            pq.push(a);
        }
    }
}