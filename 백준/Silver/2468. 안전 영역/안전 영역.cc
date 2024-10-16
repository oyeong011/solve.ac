#include<bits/stdc++.h>
using namespace std;
int x, y, n, m, ny, nx, ret, a[104][104], visited[104][104], cnt, result = 1;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
void dfs(int y, int x, int d){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(nx < 0 || ny < 0|| nx >= n || ny >= n)continue;
        if(a[ny][nx] > d && !visited[ny][nx])dfs(ny, nx, d);
    }
    return;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    cnt = 1;
    while (cnt < 101) {
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        ret = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] > cnt && !visited[i][j]){
                    dfs(i, j, cnt);
                    ret++;
                }
            }
        }
        result = max(result, ret);
        cnt++;
    }
    cout << result;

    return 0;
}