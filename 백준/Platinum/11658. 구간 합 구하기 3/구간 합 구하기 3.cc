#include<bits/stdc++.h>
using namespace std;
#define max_n 1025
int n, m, a[max_n][max_n], bit[max_n][max_n];
void update(int y, int x, int val) {
    while (y <= n) {
        int j = x;
        while (j <= n) {
            bit[y][j] += val;
            j += j & -j;
        }
        y += y & -y;
    }
}
int sum(int y, int x) {
    int s = 0;
    while (y) {
        int j = x;
        while (j) {
            s += bit[y][j];
            j -= j & -j;
        }
        y -= (y&-y);
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            update(i, j, a[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        int type; cin >> type;
        if (type == 1) {
            int y1, x1, y2, x2;
            cin >> y1 >> x1 >> y2 >> x2;
            cout << sum(y2, x2) - sum(y1 - 1, x2) - sum(y2, x1 - 1) + sum(y1 - 1, x1 - 1) << '\n';
        } else {
            int y, x, val;
            cin >> y >> x >> val;
            update(y, x, val - a[y][x]); a[y][x] = val;
        }
    }
}