#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, dp[1000004];
void go(int val){
    if(val == 0)return;
    cout << val << " ";
    if(val % 3 == 0 && dp[val] == dp[val / 3] + 1)go(val / 3);
    else if(val % 2 == 0 && dp[val] == dp[val / 2] + 1)go(val / 2);
    else if(val - 1 >= 0 && dp[val] == dp[val - 1] + 1)go(val - 1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    fill(dp, dp + 1000004, INF);
    dp[1] = 0;
    for(int i = 1; i <=n; i++){
        if(i % 3 == 0)dp[i] = min(dp[i / 3] + 1, dp[i]);
        if(i % 2 == 0)dp[i] = min(dp[i / 2] + 1, dp[i]);
        dp[i] = min(dp[i - 1] + 1, dp[i]);
    }
    
    cout << dp[n] << "\n";
    go(n);
}

