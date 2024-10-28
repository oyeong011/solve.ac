#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m;
int a[104][104], visited[104][104];
vector<pair<int, int>> edgeList;
void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[ny][nx])continue;
        if (a[ny][nx] == 1){ edgeList.push_back({ny, nx});visited[ny][nx] = 1;}
        else dfs(ny, nx);
    }
}
bool isEnd() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1)return false;
        }
    }
    return true;
}
// void printDebug(int cnt) {
//     cout << cnt << "번째 시도" << "\n";
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cout << a[i][j] << ' ';
//         }
//         cout << '\n';
//     }
//     cout << '\n';
//
// }
int solve() {
    int cnt = 0;
    while (true){
        dfs(0, 0);
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        for (auto e : edgeList) a[e.first][e.second] = 0;
        cnt++;
        if (isEnd()) return cnt;
        edgeList.clear();
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    cout << solve() << "\n";
    cout << edgeList.size() << "\n";

}