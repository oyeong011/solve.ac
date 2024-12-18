#include<bits/stdc++.h>
using namespace std;
int n, m, x, u, v, w, ret;
int dist[1001], dist2[1001];
bool visited[1001];
const int INF = 987654321;
vector<pair<int, int>> adj[1001], adj2[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int *dist, vector<pair<int, int>> *adj){
    pq.push({0, x});
    dist[x] = 0;
    while(pq.size()){
        int here = pq.top().second, here_dist = pq.top().first;
        pq.pop();
        if(dist[here] != here_dist) continue;
        for(auto [_dist, _there] : adj[here]){
            if(dist[_there] > dist[here] + _dist){
                dist[_there] = dist[here] + _dist;
                pq.push({dist[_there], _there});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> x;
    fill(dist, dist + 1001, INF);
    fill(dist2, dist2 + 1001, INF);

    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj2[v].push_back({w, u});
    }
    dijkstra(dist, adj);
    dijkstra(dist2, adj2);
    for(int i = 1; i <= n; i++){
        if(i == x) continue;
        ret = max(ret, dist[i] + dist2[i]);
    }
    cout << ret << "\n";
    return 0;
}