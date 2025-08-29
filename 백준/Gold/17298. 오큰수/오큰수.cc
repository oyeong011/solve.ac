#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    
    vector<int> v(n);
    vector<int> ret(n, -1);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && v[st.top()]<=v[i])st.pop();
        if(!st.empty())ret[i] = v[st.top()];
        st.push(i);
    }
    for(int i=0;i<n;i++)cout << ret[i] << " ";
    return 0;
}