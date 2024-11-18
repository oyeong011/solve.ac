#include<bits/stdc++.h>
using namespace std;
int t, n, k, mp[1004], visited[1004], cnt;
vector<pair<int,int>> v;
vector<int> vt;
void roll(int idx, int dir) {
    if (dir == 1) {
        int last_bit = 1 & mp[idx];
        mp[idx] >>= 1;
        if (last_bit) mp[idx] |= (1 << 7);
    } else {
        int first_bit = mp[idx] & (1 << 7);
        mp[idx] <<= 1;
        if (first_bit) mp[idx] |= 1;
        mp[idx] &= (1 << 8) - 1;
    }
}

void go(int idx, int dir) {
    int idxL = idx - 1, idxR = idx + 1;
    visited[idx] = 1;

    if (idxL >= 0 && !visited[idxL]) {
        if ((mp[idxL] & (1 << 5)) > 0 != (mp[idx] & (1 << 1)) > 0) {
            go(idxL, -1 * dir);
        }
    }
    if (idxR < t && !visited[idxR]) {
        if ((mp[idxR] & (1 << 1)) > 0 != (mp[idx] & (1 << 5)) > 0) {
            go(idxR, -1 * dir);
        }
    }
    roll(idx, dir);
}

void get_cnt() {
    cnt = 0;
    for (int i = 0; i < t; i++) {
        if (mp[i] & (1 << 7)) cnt++;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if ((s[j]) == '1') mp[i] |= 1;
            mp[i] <<= 1;
        }
        mp[i] >>= 1;
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b; a--;
        memset(visited,0, sizeof(visited));
        go(a, b);

    }

    get_cnt();
    cout << cnt << '\n';
    return 0;
}