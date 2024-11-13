#include<bits/stdc++.h>
using namespace std;
string a, b;
vector<int> v;
int z;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> a >> b;
    if (a.length() > b.length()) {
        swap(a, b);
    }
    for(int i = 0; i < a.length(); i++) {
        int x = a[a.length() - 1 - i] - '0', y = b[b.length() - 1 - i] - '0';
        int sum = x + y + z;
        z = sum / 10;
        v.push_back(sum % 10);
    }
    for (int i = a.length(); i < b.length(); i++) {
        int y = b[b.length() - 1 - i] - '0';
        int sum = y + z;
        z = sum / 10;
        v.push_back(sum % 10);
    }
    if (z > 0) v.push_back(z);
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        cout << v[i];
    }
}