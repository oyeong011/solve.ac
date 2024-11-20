#include <iostream>
#include <cstring>
using namespace std;

int map[101][101];
int R, C, m;
int s[10001];
int d[10001];
int z[10001];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

int catchShark(int x) {
    int ret = 0;
    for (int y = 1; y <= R; y++) {
        if (map[y][x] != -1) {
            ret = z[map[y][x]];
            map[y][x] = -1;
            break;
        }
    }
     
    return ret;
}

void moveSharks() {
    int temp[101][101] = { -1, };
    memset(temp, -1, sizeof(temp));
    for (int y = 1; y <= R; y++) 
        for (int x = 1; x <= C; x++) 
            if (map[y][x] != -1) {
                int ss = s[map[y][x]];
                int sy = y;
                int sx = x;
                int sd = d[map[y][x]];
               

                while (ss > 0) {
                    if (sd == 0) {
                        if (ss >= sy) {
                            ss = ss - sy + 1;
                            sy = 1;
                            sd = 1;
                        }
                        else {
                            sy -= ss;
                            ss = 0;
                        }
                    }
                    else if (sd == 1) {
                        if (ss + sy > R) {
                            ss = ss - (R - sy);
                            sy = R;
                            sd = 0;
                        }
                        else {
                            sy += ss;
                            ss = 0;
                        }
                    }
                    else if (sd == 2) {
                        if (ss + sx > C) {
                            ss = ss - (C - sx);
                            sx = C;
                            sd = 3;
                        }
                        else {
                            sx += ss;
                            ss = 0;
                        }
                    }
                    else {
                        if (ss >= sx) {
                            ss = ss - sx + 1;
                            sx = 1;
                            sd = 2;
                        }
                        else {
                            sx -= ss;
                            ss = 0;
                        }
                    }
                }
                d[map[y][x]] = sd;
                if (temp[sy][sx] != -1) 
                    temp[sy][sx] = z[temp[sy][sx]] > z[map[y][x]] ? temp[sy][sx] : map[y][x];
                else temp[sy][sx] = map[y][x];
            }
    for (int y = 1; y <= R; y++)
        for (int x = 1; x <= C; x++)
            map[y][x] = temp[y][x];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    memset(map, -1, sizeof(map));
    cin >> R >> C >> m;

    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c >> s[i] >> d[i] >> z[i];
        d[i]--;
        if (d[i] == 0 || d[i] == 1) s[i] = s[i] % (2 * (R - 1));
        else s[i] = s[i] % (2 * (C - 1));
        map[r][c] = i;
    }
    int ret = 0;
    for (int i = 1; i <= C; i++) {
        ret += catchShark(i);
        moveSharks();   
    }
    cout << ret << endl;
}