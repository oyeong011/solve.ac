#include<bits/stdc++.h>
using namespace std;

int n, m, cnt, tmp;
vector<int> v;

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    
    int left =0, right = n-1;
    while(left < right){
        if(v[left] + v[right] == m){
            left++;
            right--;
            cnt++;
        }else if(v[left] + v[right] < m){
            left++;
        }else{
            right--;
        }
    }
    cout << cnt;
    return 0;
}