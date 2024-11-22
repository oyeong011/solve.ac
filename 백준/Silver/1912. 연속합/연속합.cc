#include<bits/stdc++.h>
using namespace std;
int n, mp[100004] = {0,}, ret = -123456789;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> mp[i];
        ret = max(ret, mp[i]);

        if (mp[i - 1] <= 0)continue;

        mp[i] = mp[i - 1] + mp[i];
        ret = max(ret, mp[i]);
    }

    cout << ret << '\n';


}