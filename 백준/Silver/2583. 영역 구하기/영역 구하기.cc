#include<bits/stdc++.h>
using namespace std;
#define y1 aaaa
int m, n, k, x, y, nx, ny, a[104][104], visited[104][104], x1, x2, y1, y2;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<int> ret;
int dfs(int y, int x){
    visited[y][x] = 1;
    int ret = 1;
    for(int i = 0; i < 4; i++){
        nx = x + dx[i];
        ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[ny][nx] == 1)continue;
        if(a[ny][nx] == 1)continue;
        ret += dfs(ny, nx);
    }
    return ret;
}
int main(){
    cin >> m >> n >> k;
    for(int i = 0; i < k; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int x = x1; x < x2; x++){
            for(int y = y1; y < y2; y++){
                a[y][x] = 1;
            }
        }
    }
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] != 1 && visited[i][j] == 0){
                ret.push_back(dfs(i, j));
            }
        }
    }
    sort(ret.begin(), ret.end());
    cout << ret.size() << "\n";
    for(int a : ret) cout << a << " ";
    return 0;
}