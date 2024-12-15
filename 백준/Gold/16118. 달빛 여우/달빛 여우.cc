#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
typedef pair<int, int> PP;
typedef tuple<int, int, bool> TI;
int n, m, a, b, d, ret, here, cnt, dist[4001], dist_wolf[4001][2];
vector<PP> adj[4001];
void dikstra(){
    fill(dist, dist + 4001, INF);
    priority_queue<PP, vector<PP>, greater<PP>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        int here = pq.top().second;
        int here_dist = pq.top().first;
        pq.pop();
        if(dist[here] != here_dist) continue;
        for(PP there : adj[here]){
            int next = there.second;
            int d = there.first;
            if(dist[next] > dist[here] + d){
                dist[next] = dist[here] + d;
                pq.push({dist[next], next});
            }
        }
    }
}
void dikstra2(){
    fill(&dist_wolf[0][0], &dist_wolf[0][0] + 4001 * 2, INF);
    priority_queue<TI, vector<TI>, greater<TI>> pq;
    dist_wolf[1][0] = 0;
    pq.push({0, 1, 0});
    while(!pq.empty()){
        int d, here, cnt;
        tie(d, here, cnt) = pq.top();
        pq.pop();
        if(dist_wolf[here][cnt] != d) continue;
        for(PP there : adj[here]){
            int next = there.second;
            int d = !cnt ? there.first / 2 : there.first * 2;
            if(dist_wolf[next][!cnt] > dist_wolf[here][cnt] + d){
                dist_wolf[next][!cnt] = dist_wolf[here][cnt] + d;
                pq.push({dist_wolf[next][!cnt], next, !cnt});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> d;
        adj[a].push_back({d * 2, b});
        adj[b].push_back({d * 2, a});
    }
    dikstra();
    dikstra2();
    for(int i = 2; i <= n; i++){
        int d = min(dist_wolf[i][0], dist_wolf[i][1]);
        if(d > dist[i]) ret++;
    }
    cout << ret;
}