#include<bits/stdc++.h>
using namespace std;
string s;
stack<int> stk;
int n, cnt, ret, d[200001];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        if (s[i] == '(')stk.push(i);
        else if (stk.size()) {
            d[i] = d[stk.top()] = 1;
            stk.pop();
        }
    }

    for (int i = 0; i < n; i++) {
        if (d[i]) {
            cnt++;
            ret = max(ret, cnt);
        } else cnt = 0;

    }
    cout << ret << '\n';
}