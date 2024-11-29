#include<bits/stdc++.h>
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int n, m, mp[54][54], dp[54][54], visited[54][54];
string s;
int dfs(int y, int x) {
    if (y < 1 || y > n || x < 1 || x > m || mp[y][x] == -1) return 0;
    if (visited[y][x]) {
        cout << -1 << "\n";
        exit(0);
    }

    int &ret = dp[y][x];
    if (ret != -1) return ret;


    visited[y][x] = 1;
    ret = -1234567;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i] * mp[y][x];
        int nx = x + dx[i] * mp[y][x];
        ret = max(ret, dfs(ny, nx) + 1);
    }

    visited[y][x] = 0;
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= m; j++) {
            if (s[j - 1] == 'H') mp[i][j] = -1;
            else mp[i][j] = s[j-1] - '0';
        }
    }
    memset(dp, -1, sizeof(dp));
    memset(visited, 0, sizeof(visited));

    int ans = dfs(1, 1);
    cout << ans << "\n";
}