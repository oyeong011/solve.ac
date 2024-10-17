#include<bits/stdc++.h>
using namespace std;
int n, m, l, r, temp, ret, j;
int main(){
    cin >> n >> m >> j;
    l = 1;
    for(int i = 0; i < j; i++){
        cin >> temp;
        r = l + m - 1;
        if(temp >= l && temp <= r)continue;
        if(temp < l){
            ret += (l - temp);
            l = temp;
        }
        if(temp > r){
            ret += (temp - r);
            l += temp - r;
        }
    }
    cout << ret << "\n";
    return 0;
}