//
// Created by 권오영 on 25. 6. 27.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    for (int i = 0; i < s.length(); i++) {
        char a = s[i];
        if (a >= 'A' && a <= 'Z') {
            if (s[i] + 13 > 90) s[i] = s[i] + 13 - 26;
            else s[i] = s[i] + 13;
        } else if (a >= 'a' && a <= 'z') {
            if (s[i] + 13 > 122) s[i] = s[i] + 13 - 26;
            else s[i] = s[i] + 13;
        }
    }

    cout << s;
    return 0;
}
