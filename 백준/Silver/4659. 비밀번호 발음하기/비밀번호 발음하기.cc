#include<bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s;
    while (cin >> s && s != "end") {
        int vCnt = 0, comCnt = 0;
        bool flag = false;
        bool isContain_vo = false;
        char prev = '\0';

        for (char it : s) {
            if (isVowel(it)) {
                vCnt++; comCnt = 0; isContain_vo = true;
            } else {
                comCnt++; vCnt = 0;
            }
            
            if (comCnt == 3 || vCnt == 3) {
                flag = true;
                break;
            }
            
            if (prev == it && (it != 'e' && it != 'o')) {
                flag = true;
                break;
            }
            
            prev = it;
        }

        if (flag || !isContain_vo) {
            cout << "<" << s << "> is not acceptable.\n";
        } else {
            cout << "<" << s << "> is acceptable.\n";
        }
    }

    return 0;
}