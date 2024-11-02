#include<bits/stdc++.h>
using namespace std;
int n, k;
const int INF = 100004;
vector<int> visited(INF, -1);
vector<int> path(INF, -1);

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> n >> k;
    queue<int> q;
    q.push(n);
    visited[n] = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == k) {break;}
        for (int next : {cur - 1, cur + 1, cur * 2}) {
            if (next < 0 || next > INF)continue;
            if (visited[next] == -1) {
                visited[next] = visited[cur] + 1;
                path[next] = cur;
                q.push(next);
            }
        }
    }
    cout << visited[k] << "\n";
    vector<int> ans;
    for (int i = k; i != -1; i = path[i]) {
        ans.push_back(i);
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans) {
        cout << i << " ";
    }
}