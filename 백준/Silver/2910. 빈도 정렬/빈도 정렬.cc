#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll INF = 1e18;
int n, c, a[1004];
typedef long long ll;
map<int, int> mp, mp_f;
vector<pair<int,int>> v;
bool cmp(pair<int,int> a, pair<int, int> b){
    if(a.first == b.first){
        return mp_f[a.second] < mp_f[b.second];
    }
    return a.first > b.first;
}
int main(){
    cin >> n >> c;
    for(int i = 0 ; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
        if(mp_f[a[i]] == 0)mp_f[a[i]] = i + 1;
    }
    
    for(auto it : mp){
        v.push_back({it.second, it.first});
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(auto i : v){
        for(int j = 0; j < i.first; j++){
            cout << i.second << " ";
        }
    }
    
}