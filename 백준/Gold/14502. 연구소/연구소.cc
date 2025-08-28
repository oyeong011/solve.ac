#include<bits/stdc++.h>
using namespace std;
int n, m, ret;
int a[10][10], vis[10][10];
vector<pair<int, int>> vList, wList;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void dfs(int y, int x){
    for(int i = 0;i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || vis[ny][nx] || a[ny][nx] == 1)continue;
        vis[ny][nx] = 1;
        dfs(ny, nx);
    }
}
int sol(){
    fill(&vis[0][0], &vis[0][0] + 100, 0);
    for(pair<int, int> b : vList){
        vis[b.first][b.second] = 1;
        dfs(b.first, b.second);
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == 0 && vis[i][j] == 0)cnt++;
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
            if(a[i][j] == 2) vList.push_back({i, j});
            if(a[i][j] == 0) wList.push_back({i,j});
        }
    }
    
    for(int i=0;i<wList.size();i++){
        for(int j=0;j<i;j++){
            for(int k=0;k<j;k++){
                a[wList[i].first][wList[i].second] = 1;
                a[wList[j].first][wList[j].second] = 1;
                a[wList[k].first][wList[k].second] = 1;
                ret = max(ret, sol());
                a[wList[i].first][wList[i].second] = 0;
                a[wList[j].first][wList[j].second] = 0;
                a[wList[k].first][wList[k].second] = 0;
            }
        }
    }
    cout << ret << "\n";
    return 0;
}