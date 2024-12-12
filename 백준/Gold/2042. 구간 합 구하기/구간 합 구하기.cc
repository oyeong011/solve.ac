#include<bits/stdc++.h>
using namespace std;
#define max_n 1000005
typedef long long ll;
ll n, m, k, tmp;
vector<ll> v(max_n, 0);
void update(int idx, ll val){
    int i = idx;
    while(i <= n){
        v[i] += val;
        i += i & -i;
    }
}

ll sum(int idx){
    ll _ret = 0;
    int i = idx;
    while(i){
        _ret += v[i];
        i -= i & -i;
    }
    return _ret;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        cin >> tmp;
        update(i, tmp);
    }
    for(int i = 1; i <= m + k; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            ll diff = c - (sum(b) - sum(b - 1));
            update(b, diff);
        } else {
            cout << sum(c) - sum(b - 1) << "\n";
        }
    }
    return 0;
}

