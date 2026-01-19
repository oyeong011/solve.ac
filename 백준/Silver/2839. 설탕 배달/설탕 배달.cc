#include<bits/stdc++.h>
using namespace std;
int KG, ret;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> KG;
    
    while(KG > 0){
        if(KG % 5 == 0){
            ret += KG / 5;
            KG = 0;
        } else{
            KG -= 3;
            ret++;
        }
    }
    if(KG != 0 || ret == 0) cout << "-1" << "\n";
    else cout << ret << "\n";
}