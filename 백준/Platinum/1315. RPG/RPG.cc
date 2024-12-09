#include<bits/stdc++.h>
using namespace std;
struct game{
    int x, y, c;
};
vector<game> a;
int n, dp[1001][1001];
bool visited[101];
int rpg(int STR, int INT){
    int &ret = dp[STR][INT];
    if(ret != -1)return ret;
    ret = 0;
    int pnt = 0;
    vector<int> v;
    for(int i = 0; i < n; i++){
        if(a[i].x <= STR || a[i].y <= INT){
            ret++;
            if(!visited[i]){
                visited[i] = true;
                pnt += a[i].c;
                v.push_back(i);
            }
        }
    }

    for(int i = 0; i <= pnt; i++){
        int nSTR = min(1000, STR + i);
        int nINT = min(1000, INT + pnt - i);
        ret = max(ret , rpg(nSTR, nINT));
    }
    for(int here : v){
        visited[here] = false;
    }
    return ret;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int STR, INT, PNT;
        cin >> STR >> INT >> PNT;
        a.push_back({STR, INT, PNT});
    }
    memset(dp, -1, sizeof(dp));
    cout << rpg(1, 1);
    return 0;
}