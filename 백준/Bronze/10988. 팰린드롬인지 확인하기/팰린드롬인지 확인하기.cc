#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, tmp;
    cin >> s;
    tmp = s;
    reverse(tmp.begin(), tmp.end());
    if(tmp == s) cout << 1 <<"\n";
    else cout << 0 << "\n";
}