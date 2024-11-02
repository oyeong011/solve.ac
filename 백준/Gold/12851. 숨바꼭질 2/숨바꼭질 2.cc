#include<bits/stdc++.h>
using namespace std;
const int INF = 100001;
int n, k;
vector visited(INF, -1);
vector cnt(INF, 0);
int main() {
    cin >> n >> k;
    queue<int> q;
    q.push(n);
    visited[n] = 0;
    cnt[n] = 1;
    while (!q.empty()) {
        int now = q.front(); q.pop();

        vector next = {now - 1, now + 1, now * 2};
        for (int next_pos : next) {
            if (next_pos < 0 || next_pos >= INF)continue;
            if (visited[next_pos] == -1) {
                q.push(next_pos);
                visited[next_pos] = visited[now] + 1;
                cnt[next_pos] = cnt[now];
            } else if (visited[next_pos] == visited[now] + 1) {
                cnt[next_pos] += cnt[now];
            }
        }
    }
    cout << visited[k] << '\n';
    cout << cnt[k] << '\n';
}