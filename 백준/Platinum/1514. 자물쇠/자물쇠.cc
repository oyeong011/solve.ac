#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, a[104], b[104], dp[104][10][10][10][2];
int mod(int x){
    return x < 0 ? x + 10 : x % 10;
}
int f(int pos, int x, int y, int z, int flag){
    if(pos == n)return 0;
    int &ret = dp[pos][x][y][z][flag];
    if(ret != -1)return ret;
    if(mod(x + a[pos]) == mod(b[pos])) return ret = min(f(pos + 1, y, z, 0, 1), f(pos + 1, y, z, 0, 0));
    ret = INF;
    int f1 = flag ? 1 : -1;
    for(int i = 1; i <= 3; i++){
        ret = min(ret, 1 + f(pos, mod(x + i * f1), y, z, flag));
        ret = min(ret, 1 + f(pos, mod(x + i * f1), mod(y + i * f1), z, flag));
        ret = min(ret, 1 + f(pos, mod(x + i * f1), mod(y + i * f1), mod(z + i * f1), flag));
    }
    return ret;
}
int main(){
    cin >> n;
    string s;
    memset(dp, -1, sizeof(dp));
    cin >> s;
    for (int i = 0; i < n; i++) a[i] = s[i] - '0';
    cin >> s;
    for (int i = 0; i < n; i++) b[i] = s[i] - '0';
    cout << min(f(0, 0, 0, 0, 0), f(0, 0, 0, 0, 1));
    return 0;
}