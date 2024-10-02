#include<bits/stdc++.h>
using namespace std;
string str, str1;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> str;
    str1 = str;
    reverse(str.begin(), str.end());
    if(str == str1){
        cout << '1' << '\n';
        return 0;
    }
    cout << '0' << '\n';
}