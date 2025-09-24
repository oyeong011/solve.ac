#include<bits/stdc++.h>
using namespace std;
int k, mp[1400];
vector<int> ret[14];
void go(int s, int e, int dep){
    if(s > e)return;
    if(s == e){
        ret[dep].push_back(mp[s]);
        return;
    }
    int mid = (s+e)/2;
    ret[dep].push_back(mp[mid]);
    go(s, mid - 1, dep + 1);
    go(mid + 1, e, dep + 1);
    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> k;
    int _end = (int)pow(2, k) -1 ;
    for(int i=0;i<_end;i++){
        cin >> mp[i];
    }
    
    go(0, _end, 0);
    for(int i=0;i < k; i++){
        for(int j : ret[i]){
            cout << j << ' ';
        }
        cout << "\n";
    }
    return 0;
}