#include<bits/stdc++.h>
using namespace std;
string s;
stack<char> st;
bool flag = false;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (true) {
        flag = false;
        getline(cin, s);
        if (s[0] == '.') break;
        for (int i=0;i<s.length();i++) {
            if (s[i] == ']'){
                if(!st.empty() && st.top() == '[')st.pop();
                else flag = true;
            }
            if (s[i] == ')'){
                if(!st.empty() && st.top() == '(')st.pop();
                else flag = true;
            }
            if (s[i] == '(' || s[i] == '[') st.push(s[i]);
        }

        if (st.empty() && !flag) cout << "yes" << "\n";
        else cout << "no" << "\n";
        while (!st.empty()) st.pop();
    }
    return 0;
}