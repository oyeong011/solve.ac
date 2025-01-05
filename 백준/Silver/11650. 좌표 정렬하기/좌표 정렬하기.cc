#include<bits/stdc++.h>
using namespace std;
int n, x, y;
vector<pair<int, int>> v;
bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first)return a.second < b.second;
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), cmp);
    for(auto c : v){
        cout << c.first << " " << c.second << "\n";
    }
}