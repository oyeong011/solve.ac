#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, ret, i = 0, j = 0;
    cin >> n;
    while(i < 1000000){
        ret = i;
        j = i;
        while (j > 0) {
            ret += j % 10;
            j /= 10;
        }
        if (n == ret) {
            cout << i;
            return 0;
        }
        i++;
    }
    cout << 0;
    
}