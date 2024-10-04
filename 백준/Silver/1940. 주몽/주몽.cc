#include<bits/stdc++.h>
using namespace std;
int n, m, cnt = 0, item[15004];
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)cin >> item[i];
    if(m > 200000){
        cout << cnt << '\n';
        return 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(item[i] + item[j] == m)cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}