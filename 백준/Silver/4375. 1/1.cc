#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        long long num = 1;  
        int cnt = 1;
        
        while(1){
            if(num % n == 0){
                cout << cnt << "\n";
                break;
            }
            num = ((num * 10) % n + 1) % n; 
            cnt++;
        }
    }
    return 0;
}