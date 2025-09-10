#include<bits/stdc++.h>
using namespace std;
int T, N;
vector<pair<int, int>> v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N;
        for(int i=0;i<N;i++){
            int seo, meon;
            cin >> seo >> meon;
            v.push_back({seo, meon});
        }
        sort(v.begin(), v.end());
        int cnt = 1;
        int min_meon = v[0].second;
        for(int i=1;i<N;i++){
            if(v[i].second < min_meon){
                cnt++;
                min_meon = v[i].second;
            }
        }
        cout << cnt << "\n";
        v.clear();
    }
    return 0;
}