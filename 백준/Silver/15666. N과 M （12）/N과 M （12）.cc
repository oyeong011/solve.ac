#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v;
vector<int> current;

void dfs(int dep, int last) {
    if (dep == m) {
        for (int x : current) {
            cout << x << " ";
        }
        cout << "\n";
        return;
    }

    int prev = -1;
    for (auto num : v) {
        if (num >= last && num != prev) {  
            current.push_back(num);
            dfs(dep + 1, num);
            current.pop_back();
            prev = num;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    dfs(0, 0);
}