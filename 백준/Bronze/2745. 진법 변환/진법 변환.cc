#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int get_value(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    return c - 'A' + 10;
}

int main() {
    string N;
    int B;
    cin >> N >> B;
    
    long long result = 0;
    int len = N.length();
    
    for (int i = 0; i < len; i++) {
        int digit_value = get_value(N[i]);
        result += (long long)digit_value * pow(B, len-1-i);
    }
    
    cout << result << endl;
    
    return 0;
}