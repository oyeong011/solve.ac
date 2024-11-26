#include<bits/stdc++.h>
using namespace std;
int n, lis[1004], len, num;
pair<int, int> p[1004];
stack<int> stk;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        auto lowerPos = lower_bound(lis, lis + len, num);
        int _pos = lower_bound(lis, lis + len, num) - lis;
        if (*lowerPos == 0) len++;
        *lowerPos = num;
        p[i].first = _pos;
        p[i].second = num;
    }

    cout << len << "\n";

    for (int i = n - 1; i >= 0; i--) {
        if (p[i].first == len - 1) {stk.push(p[i].second); len--;}
    }

    while (stk.size()) {
        cout << stk.top() << " ";  stk.pop();
    }
}