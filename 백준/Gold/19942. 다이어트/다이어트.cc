#include<bits/stdc++.h>
using namespace std;
int n, min_nu[4], tmp[4], nu[15][15], ret = 1e9;
string ret_list="99999999";
const int nu_cnt = 5;
void go(int num) {
    memset(tmp, 0, sizeof(tmp));
    string ans = "";
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (num & (1 << i)) {
            for (int j = 0; j < 4; j++) {
                tmp[j] += nu[i][j];
            }
            if(ans.size()) ans += " ";  // 공백 추가
            ans += to_string(i + 1);
            sum += nu[i][4];
        }
    }
    for (int i = 0; i < 4; i++) {
        if (tmp[i] < min_nu[i]) {
            return;
        }
    }
    if (ret > sum || (ret == sum && ans < ret_list)) {
        ret = min(ret, sum);
        ret_list = ans;
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < 4; i++) {
        cin >> min_nu[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> nu[i][j];
        }
    }

    for(int i = 0; i < (1 << n); i++) {
        go(i);
    }

    if(ret == 1e9) {
        cout << -1;
    } else {
        cout << ret << "\n";
        for (char a : ret_list) cout << a;
    }
}