#include<bits/stdc++.h>
using namespace std;

int n, flag = 0;
string s;
int al[26] = {0,};

int main(){
    cin >> n;
    string s[n];
    for(int i=0; i< n;i++){
        cin >> s[i];
    }

    for(int i =0; i< n; i++)
        al[s[i][0] - 'a']++;
    
    for(int i =0; i< 26; i++){
        if(al[i] >= 5){
            cout << char(i + 'a');
            flag = 1;
        }
    }
    if(flag == 0) cout << "PREDAJA";
    return 0;
}