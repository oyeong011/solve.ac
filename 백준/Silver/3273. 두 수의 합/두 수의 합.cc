#include<bits/stdc++.h>
using namespace std;
int n, lp, rp, x, a, ret;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    cin >> x;
    lp = 0; rp = v.size() - 1;
    sort(v.begin(), v.end());
    while (lp < rp) {
        if (v[lp] + v[rp] > x)rp--;
        else if (v[lp] + v[rp] < x)lp++;
        else if (v[lp] + v[rp] == x) {
            ret++;
            lp++; rp--;
        }
    }

    cout << ret << "\n";
}