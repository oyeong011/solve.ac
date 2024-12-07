#include<bits/stdc++.h>
using namespace std;
int n, m, c, dp[24][1 << 14][24], a[14];
int go(int idx, int bo, int cp){
    if(idx == m) return 0;
    int &ret = dp[idx][bo][cp];
    if(ret) return ret;
    ret = max(ret, go(idx + 1, bo, c));
    for(int i = 0; i < n; i++){
        int isBo = (1 << i) & bo;
        int isCp = (cp - a[i]) >= 0;
        if(!isBo && isCp) ret = max(ret, go(idx, bo | (1 << i), cp - a[i]) + 1);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> c;
    for(int i = 0; i < n; i++)cin >> a[i];
    cout << go(0, 0, c) << "\n";
    return 0;
}