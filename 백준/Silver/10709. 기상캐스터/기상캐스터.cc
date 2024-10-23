#include <bits/stdc++.h>
using namespace std;
char c[104][104];
int ret[104][104],h, w ;
string s;

void go(int i) {
    bool flag = false;
    int cnt = 0;
    for (int j = 0; j < w; j++) {
        if (c[i][j] == 'c') {
            flag = true;
            cnt = 0;
        }
        if (flag)ret[i][j] = cnt++;
    }
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> h >> w;
    fill(&ret[0][0], &ret[0][0] + 104 * 104, -1);
    for (int i = 0; i < h;i++) {
        cin >> s;
        for (int j = 0; j < w; j++) {
            c[i][j] = s[j];
        }
    }
    for (int i = 0; i < h;i++) {
        go(i);
    }

    for (int i = 0; i < h;i++) {
        for (int j = 0; j < w; j++) {
            cout << ret[i][j] << " ";
        }
        cout << "\n";
    }

}