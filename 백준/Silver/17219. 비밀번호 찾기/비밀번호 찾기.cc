#include<bits/stdc++.h>
using namespace std;
map<string, string> mp;
int n, m;
string s;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        cin >> mp[s];
    }
    for (int i = 0; i < m; i++) {
        cin >> s;
        cout << mp[s] << "\n";
    }
}