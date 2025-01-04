#include<bits/stdc++.h>
using namespace std;
int n;
string s;
vector<string> v; map<string, int> mp;
bool check(string s1, string s2) {
    if (s1.size() > s2.size()) {
        return false;
    } else if (s2.size() > s1.size()) {
        return true;
    } else {
        return s1 < s2;
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), check);
    for(int i = 0; i < n; i++){
        if (!mp[v[i]]) {
            cout << v[i] << "\n";
            mp[v[i]]++;
        }
    }
}