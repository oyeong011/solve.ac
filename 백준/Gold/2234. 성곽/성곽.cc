#include<bits/stdc++.h>
using namespace std;
int n, m, ret[3], mp[54][54], visited[54][54], rcnt = 0, compSize[2504];
const int dy[] = { 0, -1, 0, 1};
const int dx[] = {-1, 0, 1, 0};
void bfs(int y, int x) {
    queue<pair<int,int>> q;
    q.push({y, x});
    visited[y][x] = rcnt + 1;
    int cnt = 0;
    while (!q.empty()) {
        int yy, xx;
        tie(yy, xx) = q.front(); q.pop();
        cnt++;
        for (int i = 0; i < 4; i++) {
            int ny = yy + dy[i], nx = xx + dx[i];
            if (ny < 0 || nx < 0 || ny >= m || nx >= n)continue;
            if (mp[yy][xx] & (1 << i) || visited[ny][nx])continue;
            visited[ny][nx] = rcnt + 1;
            q.push({ny, nx});
        }
    }
    ret[0]++;
    compSize[rcnt + 1] = cnt;
    ret[1] = max(ret[1], cnt);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mp[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j])continue;
            bfs(i, j);
            rcnt++;
        }
    }


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i + 1 < m) {
                int a = visited[i + 1][j];
                int b = visited[i][j];
                if (a != b)ret[2] = max(ret[2], compSize[a] + compSize[b]);
            }
            if (j + 1 < n) {
                int a = visited[i][j + 1];
                int b = visited[i][j];
                if (a != b)ret[2] = max(ret[2], compSize[a] + compSize[b]);
            }
        }
    }
    cout << ret[0] << ' ' << ret[1] << ' ' << ret[2];
}