#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int R, used[10];
ll max_ret = 0, min_ret = 9999999999LL;  // 충분히 큰 값으로 초기화
char sign[14];
bool cmp(int a, int b, char c) {
    if (c == '<') {
        return a < b;
    }
    if (c == '>') {
        return a > b;
    }
}
void dfs(int depth, ll sum) {
    if (depth == R) {
        max_ret = max(sum, max_ret);
        min_ret = min(sum, min_ret);
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (used[i]) continue;
        if (cmp(sum % 10, i, sign[depth])) {
            used[i] = 1;
            dfs(depth + 1, sum * 10 + i);
            used[i] = 0;
        }
    }
    
}
int main() {
    cin >> R;
    for (int i = 0; i < R; i++) {
        cin >> sign[i];
    }

    for (ll i = 0; i < 10; i++) {
        used[i] = 1;
        dfs(0, i);
        used[i] = 0;
    }

    cout << max_ret << '\n';
    if (to_string(min_ret).length() != R + 1) {
        cout << "0" << min_ret;
    }else cout << min_ret;

}