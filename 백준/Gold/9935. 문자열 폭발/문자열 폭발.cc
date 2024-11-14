#include<bits/stdc++.h>
using namespace std;
string str, bomb;
int main(){
    cin >>str>>bomb;
    int m = bomb.size(), e = 0;
    for(int i = 0; i < str.size(); i++){
        str[e++] = str[i];
        if(e - m < 0)continue;
        bool flag = false;
        for(int j = 0; j < m; j++){
            if(str[e-m+j] != bomb[j]){
                flag = true;
                break;
            }
        }
        if(flag)continue;
        e = e-m;
    }
    str.resize(e);
    if(!str.size()){cout << "FRULA" << "\n";return 0;}
    cout << str << "\n";
}