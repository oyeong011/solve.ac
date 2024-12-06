#include<bits/stdc++.h>
using namespace std;
int n, k, dp[104][100004];
struct B{
    int t, pay;
};
B a[104], b[104];
int go(int here, int time){
    if(here == n)return 0;
    int &ret = dp[here][time];
    if(ret) return ret;
    ret = -1e7;
    if(time - a[here].t >= 0) ret = max(ret, go(here + 1, time - a[here].t) + a[here].pay);
    if(time - b[here].t >= 0) ret = max(ret, go(here + 1, time - b[here].t) + b[here].pay);
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i].t >> a[i].pay >> b[i].t >> b[i].pay;
    }
    cout << go(0, k);

}