#include<bits/stdc++.h>
using namespace std;
int n, m, parent[500000], ans;
int find(int u) {
    if (parent[u] == u) return u;
    else return parent[u] = find(parent[u]);
}

bool union_node(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return true;
    parent[u] = v;
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (union_node(u, v)) {
            ans = i;
            break;
        }
    }

    if (ans == 0) cout << 0;
    else cout << ans;
}