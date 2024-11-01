#include<bits/stdc++.h>
using namespace std;
int n, l, r, ret, adj[54][54], visited[54][54];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
vector<pair<int, pair<int, int>>> v;
void dfs(int y, int x){
    visited[y][x] = 1;
    v.push_back({adj[y][x], {y, x}});
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i], nx = x + dx[i];
        if(ny < 0 || nx < 0 || nx >= n || ny >= n || visited[ny][nx])continue;
        if(abs(adj[y][x] - adj[ny][nx]) >= l && abs(adj[y][x] - adj[ny][nx]) <= r){
            dfs(ny, nx);
        }
    }
    return;
}
void makeAvg(){
    if(v.size() <= 1)return;
    int sum = 0;
    for(auto& a : v){
        sum += a.first;
    }
    sum = sum / v.size();
    for(auto& a : v){
        adj[a.second.first][a.second.second] = sum;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> adj[i][j];
        }
    }
    while(true){
        memset(visited, 0, sizeof(visited));
        bool flag = false;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j]){
                    v.clear();
                    dfs(i, j);
                    if(v.size() > 1){
                        makeAvg();
                        flag = true;
                    }
                }
            }
        }
        
        if(flag)ret++;
        else break;
    }
    
    cout << ret;
}