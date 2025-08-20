#include<bits/stdc++.h>
using namespace std;

int flag = 0;
string s, sol;
int ret[200];
char mid = '\0';

int main(){
    cin >> s;
    for(auto c : s){
        ret[c]++;
    }
    
    for(int i = 'Z'; i >= 'A'; i--){
        if(ret[i] & 1){
            flag++;
            mid = char(i);
            ret[i]--;
        }
        if(flag == 2)break;
        
        for(int j=0;j<ret[i];j+=2){
            sol += char(i);
            sol = char(i) + sol;
        }
    }
    
    if(mid)sol.insert(sol.begin() + sol.size() / 2, mid);
    if(flag > 1) cout << "I'm Sorry Hansoo";
    else cout << sol;
    return 0;
    
}