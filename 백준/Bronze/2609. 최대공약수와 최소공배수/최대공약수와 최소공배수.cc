#include<bits/stdc++.h>
using namespace std;
int x, y;
int gcd(int a, int b){
    int c = a % b;
    while(c != 0){
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}

int main(){
    cin >> x >> y;
    cout << gcd(x, y) << "\n" << lcm(x, y);
    
}