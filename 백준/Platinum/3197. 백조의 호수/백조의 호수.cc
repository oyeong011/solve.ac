#include <bits/stdc++.h>
using namespace std;
const int MAX = 1501;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int R, C;
char board[MAX][MAX];
queue<pair<int, int>> water, next_water, swan, next_swan;
bool visited[MAX][MAX], swan_visited[MAX][MAX];
pair<int, int> swan_pos[2];

void water_melting() {
    while (!water.empty()) {
        int y = water.front().first, x = water.front().second; water.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx]) continue;
            if (board[ny][nx] == 'X') {
                visited[ny][nx] = true;
                board[ny][nx] = '.';
                next_water.push({ny, nx});
            }
        }
    }
}

bool move_swan() {
    while (!swan.empty()) {
        int y = swan.front().first, x = swan.front().second; swan.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= R || nx >= C || swan_visited[ny][nx]) continue;
            if (ny == swan_pos[1].first && nx == swan_pos[1].second)
                return true;
            swan_visited[ny][nx] = true;
            if (board[ny][nx] == 'X')next_swan.push({ny, nx});
            else swan.push({ny, nx});
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin >> R >> C;

    int swan_idx = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'L') swan_pos[swan_idx++] = {i, j};
            if (board[i][j] == '.' || board[i][j] == 'L') {
                water.push({i, j});
                visited[i][j] = true;
                board[i][j] = '.';
            }
        }
    }

    swan.push(swan_pos[0]);
    swan_visited[swan_pos[0].first][swan_pos[0].second] = true;

    int days = 0;
    while (true) {
        if (move_swan()) break;
        water_melting();
        water = next_water;
        swan = next_swan;
        while (!next_water.empty()) next_water.pop();
        while (!next_swan.empty()) next_swan.pop();
        days++;
    }

    cout << days << '\n';
    return 0;
}