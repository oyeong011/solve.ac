#include<bits/stdc++.h>
using namespace std;
int mx = -4001, mn = 4001, n, sum = 0, x, maxFreq;
map<int, int> cntNum;
vector<int> v;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    v.reserve(n);

    for (int i = 0; i < n; i++) {
        cin >> x;v.push_back(x);
        mx = max(mx, x);mn = min(mn, x);
        cntNum[x]++;
        sum += x;
    }

    vector<int> modes;

    for (auto [num, freq] : cntNum) {
        if (freq > maxFreq) {
            maxFreq = freq;
        }
    }

    for (auto [num, freq] : cntNum) {
        if (freq == maxFreq) {
            modes.push_back(num);
        }
    }

    sort(v.begin(), v.end());
    sort(modes.begin(), modes.end());  // 최빈값들 정렬

    int mean = round(static_cast<double>(sum) / n);

    cout << mean << '\n'
         << v[n/2] << '\n'
         << (modes.size() > 1 ? modes[1] : modes[0]) << '\n'
         << mx - mn << '\n';

    return 0;
}