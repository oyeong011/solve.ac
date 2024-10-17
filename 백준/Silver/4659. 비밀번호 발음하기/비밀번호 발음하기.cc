#include<bits/stdc++.h>
using namespace std;
int vCnt, comCnt;
string s;
bool isVowel(int idx) {
    return (idx == 'a'|| idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    while (cin >> s && s != "end") {
        vCnt = comCnt = 0;
        bool flag = false;
        bool isContain_vo = false;
        char prev = '\0';

        for (char it : s) {
            if (isVowel(it)) {vCnt++; comCnt = 0; isContain_vo = true;}
            else {comCnt++;vCnt = 0;}
            if (comCnt == 3 || vCnt == 3){ flag = true; break;}
            if (prev == it && (it != 'e' && it != 'o')) flag = true;
            prev = it;
        }
        if (flag || !isContain_vo){ cout << "<" << s << "> is not acceptable.\n";}
        else  { cout << "<" << s << "> is acceptable.\n"; }

    }

}