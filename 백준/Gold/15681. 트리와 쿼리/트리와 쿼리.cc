#include<bits/stdc++.h>
using namespace std;
int n, r, q;
vector<int> adj[100004];
int dp[100004];

void makeTree(int curr, int parent) {
    for(int next : adj[curr]) {
        if(next != parent) {
            makeTree(next, curr);
        }
    }
}

int go(int curr, int parent) {
    dp[curr] = 1;
    
    for(int next : adj[curr]) {
        if(next != parent) {
            dp[curr] += go(next, curr);
        }
    }
    return dp[curr];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> r >> q;
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    makeTree(r, -1);
    go(r, -1); 

    for(int i = 0; i < q; i++) {
        int a;
        cin >> a;
        cout << dp[a] << "\n";
    }
    return 0;
}