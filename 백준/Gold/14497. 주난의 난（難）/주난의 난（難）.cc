#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
#define y1 a
int n, m, x1, y1, x2, y2, ret = 0, visited[304][304];
char mp[304][304];
bool flag = false;
void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (0 > ny || 0 > nx || ny >= n || nx >= m || visited[ny][nx])continue;
        if (mp[ny][nx] == '1') {visited[ny][nx] = 1; mp[ny][nx] = '0';continue;}
        if (mp[ny][nx] == '#'){flag = true;return;}
        dfs(ny, nx);
    }
}
int main() {
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mp[i][j];
        }
    }
    
    while (!flag) {
        memset(visited, 0, sizeof(visited));
        flag = false;
        ret++;
        dfs(x1 - 1, y1 - 1);
    }

    cout << ret;
}