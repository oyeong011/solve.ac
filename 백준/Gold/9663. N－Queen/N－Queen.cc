#include<bits/stdc++.h>
using namespace std;
int n, mp[15], ret;
bool check(int level){
    for(int i = 0; i < level; i++){
        if(mp[level] == mp[i] || abs(mp[level] - mp[i]) == level - i){
            return false;
        }
    }
    return true;
}

void dfs(int dep){
    if(dep == n){ret++; return;}
    for(int i = 0; i < n; i++){
        mp[dep] = i;
        if(check(dep))dfs(dep + 1);
    }
}

int main(){
    cin >> n;
    dfs(0);
    cout << ret;
}