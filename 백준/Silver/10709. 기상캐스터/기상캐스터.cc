#include<bits/stdc++.h>
using namespace std;
int h, w;
string s;
int a[101][101];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> h >> w;

    vector<int> v(h,w);
    for (int i=0;i<h;i++) {
        cin >> s;
        bool flag = false;
        int cnt = -1;
        for (int j=0;j<w;j++) {
            if (s[j] == 'c') {
                flag = true;
                cnt = -1;
            }
            if (flag) cnt++;
            else cnt = -1;
            a[i][j] = cnt;
        }
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}