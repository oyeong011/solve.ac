#include<bits/stdc++.h>
using namespace std;
struct C {
    int y; int x; vector<int> dir; int rotate = 0;
    
    C& operator=(const C& other) {
        y = other.y;
        x = other.x;
        rotate = other.rotate;
        dir = other.dir;
        return *this;
    }
}Ca[100];
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int n, m, mp[10][10], cCnt, ret = 1000;

void cnt_shadow(int temp[10][10]) {
    int shadow = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp[i][j] == 0) shadow++;
        }
    }
    ret = min(ret, shadow);
}

void caSearch(C c[]) {
    int temp[10][10];
    memcpy(temp, mp, sizeof(mp));

    for (int i = 0; i < cCnt; i++) {
        int y = c[i].y;
        int x = c[i].x;
        int ro = c[i].rotate;

        for (int d : c[i].dir) {
            int nd = (d + ro) % 4;
            int ny = y, nx = x;

            while (1) {
                ny += dy[nd];
                nx += dx[nd];
                if (ny < 0 || nx < 0 || ny >= n || nx >= m) break;
                if (mp[ny][nx] == 6) break;
                if (mp[ny][nx] != 0) continue;
                temp[ny][nx] = 100;
            }
        }
    }
    cnt_shadow(temp);
}

void go(C c[], int dep) {
    if (dep == cCnt) {
        caSearch(c);
        return;
    }

    C nextC[100];
    for(int i = 0; i < cCnt; i++) {
        nextC[i] = c[i];
    }

    for (int j = 0; j < 4; j++) {
        nextC[dep].rotate = j;
        go(nextC, dep + 1);
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 0 || mp[i][j] == 6) continue;
            Ca[cCnt].y = i;
            Ca[cCnt].x = j;
            if (mp[i][j] == 1) Ca[cCnt].dir.push_back(0);
            else if (mp[i][j] == 2) {Ca[cCnt].dir.push_back(0); Ca[cCnt].dir.push_back(2);}
            else if (mp[i][j] == 3) {Ca[cCnt].dir.push_back(0); Ca[cCnt].dir.push_back(3);}
            else if (mp[i][j] == 4) {Ca[cCnt].dir.push_back(0); Ca[cCnt].dir.push_back(2); Ca[cCnt].dir.push_back(3);}
            else if (mp[i][j] == 5) {Ca[cCnt].dir.push_back(0); Ca[cCnt].dir.push_back(1); Ca[cCnt].dir.push_back(2); Ca[cCnt].dir.push_back(3);}
            cCnt++;
        }
    }

    go(Ca, 0);
    cout << ret << '\n';
}