#include<bits/stdc++.h>
using namespace std;
int p[100002], ran[100002], N, M, cost, sum;
vector<pair<int, pair<int, int>>> v;
vector<int> res;

int find(int n){
    if(p[n] == n) return n;
    return p[n] = find(p[n]);
}

bool merge(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v)return true;
    if(ran[u] > ran[v]) swap(u, v);
    p[u] = v;
    if(ran[u] == ran[v]) ran[v]++;
    
    return false;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i = 1; i < 100002; i++){
        p[i] = i;
        ran[i] = 1;
    }
    cin >> N >> M;
    
    for(int i = 0; i < M; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        v.push_back({cost, {from, to}});
    }
    
    sort(v.begin(), v.end());
    
    for(int i = 0; i < M; i++){
        if(merge(v[i].second.first, v[i].second.second)) continue;
        cost += v[i].first;
        res.push_back(v[i].first);
        sum++;
        if(sum == N - 1){
            cost -= v[i].first;
            break;
        }
    }
    
    cout << cost;
}
