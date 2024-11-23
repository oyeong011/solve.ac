#include<bits/stdc++.h>
using namespace std;
int t, n, m, a, ret;
vector<int> vn, vm;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        for (int j = 0; j < n; j++) {
            cin >> a; vn.push_back(a);
        }
        sort(vn.begin(), vn.end());
        for (int j = 0; j < m; j++) {
            cin >> a; vm.push_back(a);
        }
        sort(vm.begin(), vm.end());

        for (auto a : vn) {
            int pos = (int)(lower_bound(vm.begin(), vm.end(), a) - vm.begin());
            ret += pos;
        }

        cout << ret << '\n';
        ret = 0;
        vn.clear(); vm.clear();
    }
}