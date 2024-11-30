#include<bits/stdc++.h>
using namespace std;
int t, w, b[1004], dp[1004][2][34];

int go(int idx, int tree, int cnt){
    if(cnt < 0)return -1e9;
    if(idx == t) return 0;
    int &ret = dp[idx][tree][cnt];
    if(ret != -1)return ret;

    return ret = max(go(idx + 1, tree, cnt), go(idx + 1, tree ^ 1, cnt - 1)) + (tree == b[idx] - 1);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t >> w;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < t; i++) cin >> b[i];
    cout << max(go(0, 0, w), go(0, 1, w - 1));
}