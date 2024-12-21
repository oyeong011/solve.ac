#include<bits/stdc++.h>
using namespace std;
const int max_n = 130;
const int INF = 987654321;
int T, N, mp[max_n][max_n], dist[max_n][max_n];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> v;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (++T) {
        cin >> N;
        if (N == 0)return 0;
        memset(mp, 0, sizeof(mp));
        fill(&dist[0][0], &dist[0][0] + max_n * max_n, INF);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> mp[i][j];
            }
        }

        pq.push(make_pair(mp[0][0], 0));
        dist[0][0] = mp[0][0];
        while (!pq.empty()) {
            int herey = pq.top().second / 1000;
            int herex = pq.top().second % 1000;
            int here_dist = pq.top().first;
            pq.pop();
            if (dist[herey][herex] != here_dist) continue;
            for (int i = 0; i < 4; i++) {
                int ny = herey + dy[i];
                int nx = herex + dx[i];
                if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                int _dist = mp[ny][nx];
                if (dist[ny][nx] > dist[herey][herex] + _dist) {
                    dist[ny][nx] = dist[herey][herex] + _dist;
                    pq.push(make_pair(dist[ny][nx], ny * 1000 + nx));
                }
            }
        }
        cout << "Problem " << T << ": " << dist[N - 1][N - 1] << "\n";
    }
}
