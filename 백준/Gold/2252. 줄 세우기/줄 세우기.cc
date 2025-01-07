#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> g(n + 1);
    vector<int> d(n + 1);
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        d[b]++;
    }
    
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(d[i] == 0)q.push(i);
    }
    
    while(q.size()){
        int now = q.front();
        q.pop();
        cout << now << ' ';
        
        for(int next : g[now]){
            d[next]--;
            if(d[next] == 0)q.push(next);
        }
    }
    
    return 0;
}