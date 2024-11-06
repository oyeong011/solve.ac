#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int a, b, n, m, h, ret = INF, visited[50][50];

bool check() {
    for (int i = 1; i <= n; i++) {
        int start = i;
        for (int j = 1; j <= h; j++) {
            if (visited[j][start]) start++;
            else if (visited[j][start - 1]) start--;
        }
        if (start != i) return false;
    }
    return true;
}

void go(int y, int x, int cnt) {
    if (cnt >= 4 || cnt >= ret) return;
    if (check()) {
        ret = min(ret, cnt);
        return;
    }
    
    int i = y;
    for (; i <= h; i++) {
        int j = (i == y ? x : 1);
        for (; j < n; j++) {
            if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1]) continue;
            visited[i][j] = 1;
            go(i, j + 1, cnt + 1);
            visited[i][j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> h;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b; 
        visited[a][b] = 1;
    }

    for (int i = 0; i < 4; i++) {
        go(1, 1, i);
        if (ret != INF) {
            cout << ret << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}