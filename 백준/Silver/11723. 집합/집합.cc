#include<bits/stdc++.h>
using namespace std;
int l = 0, n, num;
void go(string cmd) {
    if (cmd == "add") {
        cin >> num;
        l |= (1 << num - 1);
    } else if (cmd == "remove") {
        cin >> num;
        l &= ~(1 << num - 1);
    } else if (cmd == "check") {
        cin >> num;
        if (l & (1 << num - 1)) cout << 1 << "\n";
        else cout << 0 << "\n";
    } else if (cmd == "toggle") {
        cin >> num;
        if (l & (1 << num - 1)) l &= ~(1 << num - 1);
        else l |= (1 << num - 1);
    } else if (cmd == "all") {
        l = (1 << 20) - 1;
    } else if (cmd == "empty") {
        l = 0;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;
        go(cmd);
    }
    return 0;
}