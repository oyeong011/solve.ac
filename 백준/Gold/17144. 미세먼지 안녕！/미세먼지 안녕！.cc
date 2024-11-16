#include<bits/stdc++.h>
using namespace std;
int dy1[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
int dy2[] = {0, 1, 0, -1};
int R, C, T, mp[54][54], tmp[54][54], ret;
vector<pair<int, int> > v1, v2;

void dust_expand(int dy[]) {
    fill(&tmp[0][0], &tmp[0][0] + 54 * 54, 0);
    queue<pair<int, int> > q;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (mp[i][j] == -1 || !mp[i][j])continue;
            q.push({i, j});
        }
    }

    while (!q.empty()) {
        int y, x;
        tie(y, x) = q.front();
        q.pop();
        int spread = mp[y][x] / 5;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= R || nx >= C || mp[ny][nx] == -1)continue;
            tmp[ny][nx] += spread;
            mp[y][x] -= spread;
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            mp[i][j] += tmp[i][j];
        }
    }
}

vector<pair<int, int> > air_line(int sy, int sx, int dy[]) {
    vector<pair<int, int> > v;
    int cnt = 0, y = sy, x = sx;
    while (1) {
        int ny = y + dy[cnt], nx = x + dx[cnt];
        if (ny == sy && nx == sx) break;
        if (ny < 0 || nx < 0 || ny >= R || nx >= C) {
            cnt++;
            ny = y + dy[cnt], nx = x + dx[cnt];
        }
        if (ny == sy && nx == sx) break;
        y = ny, x = nx;
        v.push_back({ny, nx});
    }
    return v;
}

void go(vector<pair<int, int> > &v) {
    for (int i = v.size() - 1; i > 0; i--) {
        mp[v[i].first][v[i].second] = mp[v[i - 1].first][v[i - 1].second];
    }
    mp[v[0].first][v[0].second] = 0;
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C >> T;
    bool flag = true;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == -1) {
                if (flag) {
                    flag = false;
                    v1 = air_line(i, j, dy1);
                } else {
                    v2 = air_line(i, j, dy2);
                }
            }
        }
    }

    while (T--) {
        dust_expand(dy1);
        go(v1);
        go(v2);
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (mp[i][j] != -1) ret += mp[i][j];
        }
    }

    cout << ret << '\n';
}

