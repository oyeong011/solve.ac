#include<bits/stdc++.h>
using namespace std;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
char a[55][55];
int vis[55][55];
int row, col;

int bfs(int y, int x){
    queue<pair<int, int>> q;
    q.push({y,x});
    memset(vis, 0, sizeof(vis));
    vis[y][x] = 1;
    int max_dist = 0;
    while(!q.empty()){
        auto [yy, xx] = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int ny = yy + dy[i];
            int nx = xx + dx[i];
            if(ny < 0||nx<0||ny>=row||nx>=col)continue;
            if(vis[ny][nx] || a[ny][nx] == 'W')continue;
            q.push({ny, nx});
            vis[ny][nx] = vis[yy][xx] + 1;
            max_dist = max(max_dist, vis[ny][nx] - 1);
        }
    }
    return max_dist;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> row >> col;
    for(int i=0;i<row;i++){
        string s;
        cin >> s;
        for(int j=0;j<s.length();j++){
            a[i][j] = s[j];
        }
    }
    
    int ret=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(a[i][j] == 'L')ret = max(ret, bfs(i, j));
        }
    }
    cout << ret << "\n";
}