#include<bits/stdc++.h>
using namespace std;
int num, CNT[26], result = 0;
string str;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> num;
    for (int i = 0; i < num ; i++){
        cin >> str;
        CNT[str[0]-'a']++;
    }
    
    for(int i = 0; i< 26; i++){
        if(CNT[i]>=5){
            char a = 'a' + i;
            cout << a;
            result = 1;
        }
    }
    
    if (result == 0) {
        cout << "PREDAJA";
    }
}