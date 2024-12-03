#include<bits/stdc++.h>
using namespace std;

const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};

int n, k, a[14][14], ret;
vector<int> board[14][14];
pair<int,int> pos[11];
int dirL[11];

int findIdx(int y, int x, int num) {
    auto& v = board[y][x];
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == num) return i;
    }
    return -1;
}

bool check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j].size() >= 4) return true;
        }
    }
    return false;
}

void go() {
    while (ret <= 1000) {
        ret++;
        for (int i = 0; i < k; i++) {
            vector<int> temp;
            int y = pos[i].first;
            int x = pos[i].second;
            auto& v = board[y][x];

            int idx = findIdx(y, x, i);
            for (int j = idx; j < v.size(); j++) {
                temp.push_back(v[j]);
            }

            int ny = y + dy[dirL[i]];
            int nx = x + dx[dirL[i]];

            if (ny < 0 || nx < 0 || ny >= n || nx >= n || a[ny][nx] == 2) {
                dirL[i] = dirL[i] ^ 1;
                ny = y + dy[dirL[i]];
                nx = x + dx[dirL[i]];
                if (ny < 0 || nx < 0 || ny >= n || nx >= n || a[ny][nx] == 2) {
                    continue;
                }
            }

            if (a[ny][nx] == 1) {
                reverse(temp.begin(), temp.end());
            }

            v.erase(v.begin() + idx, v.end());
            for (const auto& j : temp) {
                board[ny][nx].push_back(j);
                pos[j] = {ny, nx};
            }

            if (check()) return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        int y, x, z;
        cin >> y >> x >> z;
        y--; x--; z--;
        board[y][x].push_back(i);
        pos[i] = {y, x};
        dirL[i] = z;
    }

    go();
    cout << (ret > 1000 ? -1 : ret) << '\n';
    return 0;
}