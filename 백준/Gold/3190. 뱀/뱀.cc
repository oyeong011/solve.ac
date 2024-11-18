#include<bits/stdc++.h>
using namespace std;
const int dy[] = {0, -1, 0, 1};
const int dx[] = {1, 0, -1, 0};
int n, k, l, mp[104][104], ret, cnt ,x ,y;
vector<pair<int, string>> v;
queue<pair<int,int>> tail;
int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b; mp[a-1][b-1] = 10;
    }
    cin >> l;
    for (int i = 0; i < l; i++) {
        int a; string c;
        cin >> a >> c;
        v.push_back({a, c});
    }
    sort(v.rbegin(), v.rend());

    x = 0, y = 0; mp[y][x] = 1;
    while (1) {
        int nx = x + dx[cnt % 4], ny = y + dy[cnt % 4];
        tail.push({y, x});
        if (nx < 0 || ny < 0 || nx >= n || ny >= n || mp[ny][nx] == 1) break;
        if (mp[ny][nx] != 10) {
            int ay, ax; tie(ay, ax) = tail.front();
            mp[ay][ax] = 0;
            tail.pop();
        }
        y = ny, x = nx, mp[ny][nx] = 1;
        ret++;
        if (v.size() && v.back().first == ret) {
            if (v.back().second == "L") cnt++;
            else cnt+=3;
            v.pop_back();
        }

    }
    cout << ret + 1 << "\n";
}