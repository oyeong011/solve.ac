#include<bits/stdc++.h>
using namespace std;
int N, arr[100004], visited[100004], a,b;
vector<int> v[100004];

void dfs(int k) {
    visited[k] = 1;
    for (auto a : v[k]) {
        if (visited[a])continue;
        arr[a] = k;
        dfs(a);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 2; i <= N; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);

    for (int i = 2; i <= N; i++) {
        cout << arr[i] << "\n";
    }
}