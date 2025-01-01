#include<bits/stdc++.h>
using namespace std;
#define y1 aaa
int n, x, y, x1, y1, x2, y2, _y[1000004], _x[1000004], ret;
vector<int> X, Y;
pair<int, int> a[100004];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        x += 500000;
        y += 500000;
        a[i] = {x, y};
        X.push_back(x);
        Y.push_back(y);
    }
    
    a[n] = a[0];
    for(int i = 0; i < n; i++){
        tie(x1, y1) = a[i];
        tie(x2, y2) = a[i + 1];
        if(x1 != x2){
            if(x1 > x2) swap(x1, x2);
            for(int j = x1 + 1; j <= x2; j++) _x[j]++;
        }
        
        if(y1 != y2){
            if(y1 > y2) swap(y1,y2);
            for(int j = y1 + 1; j <= y2; j++) _y[j]++;
        }
    }
    
    for(int a : X)ret = max(ret, _x[a]);
    for(int a : Y)ret = max(ret, _y[a]);
    cout << ret;
}