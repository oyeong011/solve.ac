#include<bits/stdc++.h>
using namespace std;
#define y1 어찌구
int n, m, mp[1025][1025], x1, x2, y1, y2;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mp[i][j];
            mp[i][j] += mp[i][j-1];
        }
    }

    for (int i = 1; i <= m; i++) {
        cin >> y1 >> x1 >> y2 >> x2;
        // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        int sum = 0;
        for (int j = y1; j <= y2; j++) {
            sum += (mp[j][x2] - mp[j][x1-1]);
        }
        cout << sum << '\n';
    }
}