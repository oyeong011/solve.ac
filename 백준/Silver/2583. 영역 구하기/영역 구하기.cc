#include<bits/stdc++.h>
using namespace std;

int m, n, k;
int a[101][101];
int vis[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int bfs(int sy, int sx){
    queue<pair<int, int>> q;
    q.push({sy, sx});
    vis[sy][sx] = 1;
    int area = 1;
    
    while(!q.empty()){
        auto [y, x]=q.front();
        q.pop();
        for(int dir = 0; dir<4;dir++){
            int ny = y +dy[dir];
            int nx = x + dx[dir];
            if(ny < 0||nx < 0 || ny >= m || nx >= n) continue;
            if(vis[ny][nx] || a[ny][nx]) continue;
            vis[ny][nx] = 1;
            q.push({ny, nx});
            area++;
        }
    }
    return area;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> m >> n >> k;
    for(int t=0;t<k;t++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int y = y1; y < y2;y++){
            for(int x = x1; x < x2; x++){
                a[y][x]=1;
            }
        }
    }
    
    vector<int> areas;
    for(int y = 0;y < m;y++){
        for(int x = 0; x < n; x++){
            if(a[y][x] || vis[y][x]) continue;
            areas.push_back(bfs(y, x));
        }
    }
    
    sort(areas.begin(), areas.end());
    
    cout << areas.size() << '\n';
    for(size_t i = 0; i < areas.size(); i++){
        cout << areas[i];
        if(i +1 < areas.size()) cout << ' ';
    }
    cout <<'\n';
    return 0;
}