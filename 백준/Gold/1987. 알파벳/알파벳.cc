#include<bits/stdc++.h>
using namespace std;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};
int R, C, vis[26], ret;
char a[24][24];

void dfs(int y, int x, int cnt) {
    ret = max(ret, cnt);
    
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
        int next = a[ny][nx] - 'A';
        if (vis[next]) continue;
        
        vis[next] = 1;
        dfs(ny, nx, cnt + 1);
        vis[next] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++) {
            a[i][j] = s[j];
        }
    }
    
    memset(vis, 0, sizeof(vis));
    vis[a[0][0] - 'A'] = 1;  // 시작 위치의 알파벳 방문 체크
    dfs(0, 0, 1);
    
    cout << ret << "\n";
    return 0;
}