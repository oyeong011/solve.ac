#include <bits/stdc++.h>
using namespace std;
string s;
bool solve(vector<char> v, string s) {
    for (auto c : s) {
        if (c == '(' || c == '[')v.push_back(c);
        else if(c ==')' || c == ']') {
            if (!v.empty() && (c ==')' && v.back() == '(' || c ==']' && v.back() == '['))v.pop_back();
            else return false;
        }
    }
    return v.empty();
}
int main() {

    while (getline(cin, s) && s != ".") {
        vector<char> v;
        if (solve(v, s))cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
}
