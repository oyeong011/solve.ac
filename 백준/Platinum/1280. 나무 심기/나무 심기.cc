#include<bits/stdc++.h>
using namespace std;
#define max_n 200004
typedef long long ll;
const ll mod = 1e9 + 7;
ll ret = 1;
int n, val;
vector<ll> tree_cnt(max_n, 0), tree_sum(max_n, 0);
ll _sum(vector<ll> &tree, int value){
    ll _ret = 0;
    int i = value;
    while(i){
        _ret += tree[i];
        i -= i & -i;
    }
    return _ret;
}

ll sum(vector<ll> &tree, int s, int e){
    if(s > e) return 0;
    return _sum(tree, e) - _sum(tree, s - 1);
}

void update(vector<ll> &tree, int x, int val){
    int i = x;
    while(i <= max_n){
        tree[i] += val;
        i += i & -i;
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> val; val++;
        if(i != 1){
            ll left = val * sum(tree_cnt, 1, val - 1) - sum(tree_sum, 1, val - 1);
            ll right = sum(tree_sum, val + 1, max_n) - val * sum(tree_cnt, val + 1, max_n);
            ret *= (left + right) % mod;
            ret %= mod;
        }
        update(tree_cnt, val, 1);
        update(tree_sum, val, val);
    }
    cout << ret << "\n";
}