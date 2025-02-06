#include<bits/stdc++.h>
using namespace std;
int word[26];
string s;
int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        word[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        cout << word[i] << " ";
    }
}