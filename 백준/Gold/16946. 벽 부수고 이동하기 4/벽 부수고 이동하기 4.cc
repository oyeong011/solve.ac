#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, mp[1004][1004], area_num[1004][1004], area_size[1000001], ret[1004][1004];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            mp[i][j] = s[j] - '0';
        }
    }

    int area_id = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == 0 && area_num[i][j] == 0) {
                queue<pair<int, int>> q;
                q.push({i, j});
                area_num[i][j] = area_id;
                int size = 0;

                while (!q.empty()) {
                    int y = q.front().first, x = q.front().second; q.pop();
                    size++;
                    for (int d = 0; d < 4; d++) {
                        int ny = y + dy[d], nx = x + dx[d];
                        if (ny >= 0 && nx >= 0 && ny < n && nx < m &&
                            mp[ny][nx] == 0 && area_num[ny][nx] == 0) {
                            q.push({ny, nx});
                            area_num[ny][nx] = area_id;
                        }
                    }
                }
                area_size[area_id] = size;
                area_id++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == 1) {
                set<int> unique_areas;
                int sum = 1;

                for (int d = 0; d < 4; d++) {
                    int ny = i + dy[d], nx = j + dx[d];
                    if (ny >= 0 && nx >= 0 && ny < n && nx < m && mp[ny][nx] == 0) {
                        unique_areas.insert(area_num[ny][nx]);
                    }
                }
                for (int area : unique_areas) {
                    sum += area_size[area];
                }
                ret[i][j] = sum % 10;
            } else {
                ret[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ret[i][j];
        }
        cout << "\n";
    }

    return 0;
}