#include<bits/stdc++.h>
using namespace std;
int n, m, a;
map<string, int> visited;
vector<int> v;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a; v.push_back(a);
    }
    sort(v.begin(), v.end());

    do {
        string s = "";
        for (int i = 0; i < m; i++) {
            s += to_string(v[i]) + " ";
        }
        if (visited[s] == 1) continue;
        cout << s << "\n";
        visited[s] = 1;
    }while (next_permutation(v.begin(), v.end()));
}