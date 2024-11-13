#include<bits/stdc++.h>
using namespace std;
int n, m, a[104][104];
int main(){
    cin >> n >> m;
    for(int k = 0; k < 2; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int num;
                cin >> num;
                a[i][j] += num;
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << ' ';
        }
        cout << "\n";
    }    
}
