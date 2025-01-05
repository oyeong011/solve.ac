#include<bits/stdc++.h>
using namespace std;
string s1, s2;
int main() {
    while (1) {
        cin >> s1; s2 = s1;
        if (s1 == "0")break;
        reverse(s1.begin(), s1.end());
        if (s1 == s2)cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
}