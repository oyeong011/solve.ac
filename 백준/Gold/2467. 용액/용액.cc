#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[100004], diff = 2e9, ret1, ret2, l, r;
int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  l = 0, r = n - 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  while (l < r){
    ll sum = a[l] + a[r];
    if(diff > abs(a[l] + a[r])){
      diff = abs(a[l] + a[r]);
      ret1 = l; ret2 = r;
    }

    if (sum < 0) l++;
    else r--;
  }

  cout << a[ret1] << " " << a[ret2] << "\n";

}