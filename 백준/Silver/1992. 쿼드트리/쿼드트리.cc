#include<bits/stdc++.h>
using namespace std;
int n;
string s;
char a[101][101];

string dfs(int y, int x, int size){
    if(size == 1) return string(1, a[y][x]);
    char b = a[y][x];
    string ret = "";
    for(int i=y;i<y+size;i++){
        for(int j=x;j<x+size;j++){
            if(b != a[i][j]){
                ret += '(';
                ret += dfs(y, x, size / 2);
                ret += dfs(y, x+size/2,size/2);
                ret += dfs(y+size/2, x, size / 2);
                ret += dfs(y +size/2, x +size /2, size /2);
                ret += ')';
                return ret;
            }
        }
    }
    return string(1, a[y][x]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<n;j++){
            a[i][j] = s[j];
        }
    }
    
    cout << dfs(0, 0, n) << "\n";
    return 0;
    
}