#include<bits/stdc++.h>
using namespace std;
int n, dist[20][20], dp[20][20][3];
bool check(int y, int x, int k){
    if(k == 0 || k == 2){
        if(!dist[y][x]) return true;
    } else if(k == 1){
        if(!dist[y][x] && !dist[y - 1][x] && !dist[y][x - 1]) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> dist[i][j];
        }
    }

    dp[1][2][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][0];
            if(check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][0];

            if(check(i + 1, j, 2))dp[i + 1][j][2] += dp[i][j][2];
            if(check(i + 1, j + 1, 1))dp[i + 1][j + 1][1] += dp[i][j][2];

            if(check(i + 1, j + 1, 1))dp[i + 1][j + 1][1] += dp[i][j][1];
            if(check(i + 1, j, 2))dp[i + 1][j][2] += dp[i][j][1];
            if(check(i, j + 1, 0))dp[i][j + 1][0] += dp[i][j][1];
        }
    }

    int ret = dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
    cout << ret << '\n';
}