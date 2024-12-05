#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[104], dp[104][21], n;
ll go(ll idx, ll sum){
    if(sum < 0 || sum > 20)return 0;
    ll &ret = dp[idx][sum];
    if(ret)return ret;
    if(idx == n - 2){
        if(sum == a[n - 1])return 1;
        return 0;
    }
    ret += go(idx + 1, sum + a[idx + 1]);
    ret += go(idx + 1, sum - a[idx + 1]);
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << go(0, a[0]);
}