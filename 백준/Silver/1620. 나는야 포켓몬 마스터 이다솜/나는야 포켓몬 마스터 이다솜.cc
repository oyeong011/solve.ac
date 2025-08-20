#include<bits/stdc++.h>
using namespace std;

int n, m;
map<string, int> nameToNum;
string numToName[100004];
string s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> s;
        nameToNum[s] = i;
        numToName[i] = s;
    }
    
    for(int i = 0; i < m; i++){
        cin >> s;
        if(isdigit(s[0])){
            int idx = stoi(s);
            cout << numToName[idx] << "\n";
        }else {
            cout << nameToNum[s] << "\n";
        }
    }
    return 0;
}