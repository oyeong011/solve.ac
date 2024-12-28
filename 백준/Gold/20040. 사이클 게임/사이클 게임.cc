#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, parent[500001], turn=0;

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    turn = 0;
    for(int i = 0; i < n; i++)parent[i]=i;

    for(int i = 0; i < m; i++) {
        turn++;
        cin >> x >> y;
        int px = find(x), py = find(y);
        if(px == py) {
            cout << turn;
            return 0;
        }
        if(px < py) parent[py] = px;
        else parent[px] = py;
    }
    cout << 0;
    return 0;

}
