#include<bits/stdc++.h>
using namespace std;
int n, m, h, ret = 4, visited[31][11];
bool check(){
    for(int i = 1; i <= n; ++i){
        int start = i;
        for(int j = 1; j <= h; ++j){
            if(visited[j][start]) start++;
            else if(visited[j][start - 1]) start--;
        }
        if(start != i)return false;
    }
    return true;
}
void go(int cnt, int goal){
    if(ret < 4)return;
    if(cnt == goal){
        if(check())ret = goal;
        return;
    }
    
    for(int j = 1; j < n; ++j){
        for(int i = 1; i <= h; ++i){
            if(visited[i][j] || visited[i][j+1] || visited[i][j-1])continue;
            visited[i][j] = 1;
            go(cnt + 1, goal);
            visited[i][j] = 0;
            while(i <= h && !visited[i][j+1] && !visited[i][j-1])++i;
        }
    }
}

int main(){
    cin >> n >> m >> h;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        visited[a][b] = 1;
    }
    
    for(int i = 0; i < 4; i++){
        go(0, i);
        if(ret != 4){
            cout << ret << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}