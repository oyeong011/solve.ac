#include<bits/stdc++.h>
using namespace std;
string s;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;

    bool flag = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'p') {
            if (i < s.size() - 1 && s[i + 1] == 'i') {
                i++;
                continue;
            }
            flag = true;
            break;
        }
        if (s[i] == 'k') {
            if (i < s.size() - 1 && s[i + 1] == 'a') {
                i++;
                continue;
            }
            flag = true;
            break;
        }
        if (s[i] == 'c') {
            if (i < s.size() - 2 && s[i + 1] == 'h' && s[i + 2] == 'u') {
                i += 2;
                continue;
            }
            flag = true;
            break;

        }
        flag = true;
        break;
    }

    if (flag) cout << "NO" << "\n";
    else cout << "YES" << "\n";
}
