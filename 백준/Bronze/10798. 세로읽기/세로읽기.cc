#include<bits/stdc++.h>
using namespace std;
vector<char> v[15];
int main(){
    for(int i = 0; i < 5; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            v[j].push_back(s[j]);
        }
    }
    for(auto a : v){
        for(auto b : a){
            cout << b;
        }
    }
}