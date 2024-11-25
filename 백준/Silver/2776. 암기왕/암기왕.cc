#include<bits/stdc++.h>
using namespace std;
int t, n, m, a;
vector<int> v1, v2;
int go(int target) {
    int lo = 0, hi = v1.size() - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (v1[mid] == target) return 1;
        else if (v1[mid] < target) lo = mid + 1;
        else if (v1[mid] > target) hi = mid - 1;
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a;
            v1.push_back(a);
        }
        sort(v1.begin(), v1.end());
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> a;
            cout << go(a) << "\n";
        }
        v1.clear();
    }
}