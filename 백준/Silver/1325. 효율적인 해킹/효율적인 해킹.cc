#include<bits/stdc++.h>
using namespace std;
int n, m, dp[10004], visited[10004], mx;
vector<int> v[10004];
int dfs(int here){
    visited[here] = 1;
    int ret = 1;
    for(int there : v[here]){
        if(visited[there])continue;
        ret += dfs(there);
    }
    return ret;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }
    
    for(int i = 1; i <= n; i++){
        memset(&visited[0], 0, sizeof(visited));
        dp[i] = dfs(i);
        mx = max(mx, dp[i]);
    }
    
    for(int i = 0; i <= n; i++){
        if(mx == dp[i])cout << i << " ";
    }
    return 0;
}