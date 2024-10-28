#include<bits/stdc++.h>
using namespace std;
int n, r, root, temp;
vector<int> v[54];
int dfs(int here){
    int ret = 0;
    int child = 0;
    for(int there : v[here]){
        if(r == there) continue;
        ret += dfs(there);
        child++;
    }
    if(child == 0)return 1;
    return ret;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        if(temp == -1) root = i;
        else v[temp].push_back(i);
    }
    cin >> r;
    if(r == root){
        cout << "0" << "\n";
        return 0;
    }
    cout << dfs(root) << "\n";
    return 0;
}