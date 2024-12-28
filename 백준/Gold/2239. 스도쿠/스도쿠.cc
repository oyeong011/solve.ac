#include<bits/stdc++.h>
using namespace std;
int mp[9][9];

bool ok(int y, int x, int n) {
    for (int i = 0; i < 9; i++) {
        if (mp[y][i] == n || mp[i][x] == n) return false;
    }

    y = (y / 3) * 3;
    x = (x / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mp[y + i][x + j] == n)return false;
        }
    }

    return true;
}

bool go() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (mp[i][j]) continue;
            for (int k = 1; k <= 9; k++) {
                if (ok(i, j, k)) {
                    mp[i][j] = k;
                    if (go()) return true;
                    mp[i][j] = 0;
                }
            }
            return false;
        }
    }
    return true;
}

void print() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << mp[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 9; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 9; j++) {
            mp[i][j] = s[j] - '0';
        }
    }

    go();
    print();


}