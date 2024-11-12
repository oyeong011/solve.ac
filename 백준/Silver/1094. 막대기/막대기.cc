#include<bits/stdc++.h>
using namespace std;
int n, ret;

int main() {
    cin >> n;
    for (int i = 0; i < 7; i++) {
        if (n & (1 << i))ret++;
    }
    cout << ret << "\n";
}