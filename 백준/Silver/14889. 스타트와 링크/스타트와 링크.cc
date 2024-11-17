#include<bits/stdc++.h>
using namespace std;
int n, recordA, recordB, ret = 1e9, mp[24][24];
void solve() {

    for (int i = 1; i < (1 << n); i++) {
        if (__builtin_popcount(i) != n/2)continue;
        vector<int> teamA, teamB;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) teamA.push_back(j);
            else teamB.push_back(j);
        }
        int sumA = 0, sumB = 0;
        for (int a = 0; a < n/2; a++) {
            for (int b = 0; b < n/2; b++) {
                if (a != b) {
                    sumA += mp[teamA[a]][teamA[b]];
                    sumB += mp[teamB[a]][teamB[b]];
                }
            }
        }
        ret = min(abs(sumA - sumB), ret);
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mp[i][j];
        }
    }

    solve();
    cout << ret << "\n";

}