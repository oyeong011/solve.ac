#include<bits/stdc++.h>
using namespace std;
const int max_n = 104;
int n, m, x, y, ny, nx, a[max_n][max_n], visited[max_n][max_n];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string row;
        cin >> row;
        for(int j = 0; j < m;j++){
            a[i][j] = row[j] - '0';
        }
    }
    
    queue<pair<int, int>> q;
    visited[0][0] = 1;
    q.push({0,0});
    while(q.size()){
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            ny = y + dy[i];
            nx = x + dx[i];
            if(ny < 0 || nx < 0 || nx >= m || ny >= n || a[ny][nx] == 0)continue;
            if(visited[ny][nx])continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    cout << visited[n-1][m-1];
    
}