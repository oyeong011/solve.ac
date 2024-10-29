#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int>> chickenList, homeList, selectedList;
int permutation(int idx){
    if(selectedList.size() == m){
        int ret2 = 0;
        for(auto a : homeList){
            int temp = 1e9;
            for(auto b : selectedList){
                temp = min(temp, abs(a.first - b.first) + abs(a.second - b.second));
            }
            ret2 += temp;
        }
        return ret2;
    }
    int ret = 1e9;
    for(int i = idx; i < chickenList.size(); i++){
        selectedList.push_back(chickenList[i]);
        ret = min(ret, permutation(i + 1));
        selectedList.pop_back();
    }
    return ret;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int a;
            cin >> a;
            if(a == 2)chickenList.push_back({i, j});
            if(a == 1)homeList.push_back({i, j});
        }
    }
    cout << permutation(0) << "\n";
}