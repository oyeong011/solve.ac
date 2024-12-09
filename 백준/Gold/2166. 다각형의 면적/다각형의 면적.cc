#include<bits/stdc++.h>
using namespace std;
int n;
double x, y;
vector<double> v1, v2;
double solve(vector<double> x, vector<double> y, int n){
    double ans = 0.0;
    for(int i = 2; i < n; i++){
        ans += x[0] * y[i - 1] + x[i - 1] * y[i] + x[i] * y[0];
        ans -= x[0] * y[i] + x[i - 1] * y[0] + x[i] * y[i - 1];
    }
    return ans;
}
int main(){
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        v1.push_back(x); v2.push_back(y);
    }
    double ans = solve(v1, v2, n) / 2;
    cout << fixed << setprecision(1) << abs(ans) << "\n";
    return 0;
}