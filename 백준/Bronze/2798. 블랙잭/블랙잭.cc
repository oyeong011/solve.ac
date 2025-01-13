#include<bits/stdc++.h>
using namespace std;
int n, m, arr[104], card, maxSet;
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    

    for(int i = 0; i < n - 2; i++){
        for(int j = i + 1; j < n - 1; j++){
            for(int k = j + 1; k < n; k++){
                card = arr[i] + arr[j] + arr[k];
                if(card <= m && maxSet < card) maxSet = card;
            }
        }
    }
    cout << maxSet;
    
}