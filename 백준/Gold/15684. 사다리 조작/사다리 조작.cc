#include<bits/stdc++.h>
using namespace std;
int n, m, h, ans = 4;
bool visited[31][11];

bool check() {
    for(int i = 1; i <= n; ++i) {
        int cur = i;
        for(int j = 1; j <= h; ++j) {
            if(visited[j][cur]) ++cur;
            else if(visited[j][cur-1]) --cur;
        }
        if(cur != i) return false;
    }
    return true;
}

void go(int cnt, int goal) {
    if(ans < 4) return;  
    if(cnt == goal) {    
        if(check()) ans = goal;
        return;
    }
    
    for(int j = 1; j < n; ++j) {
        for(int i = 1; i <= h; ++i) {
            if(visited[i][j] || visited[i][j+1] || visited[i][j-1]) continue;
            visited[i][j] = 1;
            go(cnt + 1, goal);
            visited[i][j] = 0;
            while(i <= h && !visited[i][j-1] && !visited[i][j+1]) ++i;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> h;
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        visited[a][b] = 1;
    }
    
    for(int i = 0; i < 4; ++i) {
        go(0, i);
        if(ans != 4) {
            cout << ans << '\n';
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}