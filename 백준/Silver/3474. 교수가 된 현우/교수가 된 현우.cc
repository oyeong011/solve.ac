#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll cntZero(ll n){
    ll cnt =0;
    for(ll i = 5;i<=n;i*=5){
        cnt += n / i;
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while(T--){
        ll N;
        cin >> N;
        cout << cntZero(N) << "\n";
    }
    return 0;
}