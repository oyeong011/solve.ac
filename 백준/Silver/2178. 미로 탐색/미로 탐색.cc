#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[101][101];
string s;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<m;j++)
            a[i][j] = s[j] - '0';
    }
    queue<pair<int,int>> q;
    q.push({0, 0});
    a[0][0] = 1;
    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
            if(a[nx][ny] != 1) continue;
            a[nx][ny] = a[x][y] + 1;
            q.push({nx, ny});
        }
    }
    cout << a[n-1][m-1];
    return 0;
}