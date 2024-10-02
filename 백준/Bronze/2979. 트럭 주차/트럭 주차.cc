#include<bits/stdc++.h>
using namespace std;
vector<int> ABC(4);
vector<int> CNT(101);
int in, out;
int result;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> ABC[1] >> ABC[2] >> ABC[3];

    for(int i = 0; i < 3; i++){
        cin >> in >> out;
        for(int j = in; j < out; j++){
            CNT[j]++;
        }
    }

    for(int i = 1; i < 100; i++){
        result += ABC[CNT[i]] * CNT[i];
    }
    
    cout << result << '\n';
}