#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ret, a[100004], visited[100004], s, e;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)cin >> a[i];
    
    while(e < n){
        if(!visited[a[e]]) visited[a[e++]]++;
        else {
            ret += (e - s);
            visited[a[s++]]--;
        }
    }
    ret += (ll) (e - s) * (e - s + 1) / 2;
    cout << ret;
                                   
}