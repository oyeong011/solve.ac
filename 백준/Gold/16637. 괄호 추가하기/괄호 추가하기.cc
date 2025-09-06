#include<bits/stdc++.h>
using namespace std;
int n, ret = -1e9;
string s;
int calc(int a, int b, char c){
    if(c == '+')return a + b;
    if(c == '-')return a - b;
    if(c == '*')return a * b;
    return 0;
}
void dfs(int idx, int val){
    if(idx >= n){
        ret = max(ret, val);
        return;
    }
    
    char op = idx == 0 ? '+' : s[idx - 1];
    int nextVal = calc(val, s[idx] - '0', op);
    dfs(idx + 2, nextVal);
    
    if(idx + 2 < n){
        int bracket = calc(s[idx]-'0', s[idx+2] - '0', s[idx+1]);
        int nextVal = calc(val, bracket, op);
        dfs(idx + 4, nextVal);
    }
}
int main(){
    cin >> n >> s;
    dfs(0, 0);
    cout << ret;
}