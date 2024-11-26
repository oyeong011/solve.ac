#include<bits/stdc++.h>
using namespace std;
int n;
double ret = -1, a;
vector<double> v;
void solve(int idx) {
    if (v[idx] <= 1) {
        ret = max(ret, v[idx]);
        return;
    }
    double sum = 1;
    for (int i = idx; i < n; i++) {
        sum *= v[i];
        if (sum <= 1) return;
        ret = max(ret, sum);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a; v.push_back(a);
    }

    for (int i = 0; i < n; i++) {
        solve(i);
    }
    cout << fixed << setprecision(3) << ret << '\n';

}