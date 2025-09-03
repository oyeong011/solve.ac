#include<bits/stdc++.h>
using namespace std;
int visited[64][64][64], a[3], n;
int _a[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 3, 9},
    {1, 9, 3}
};
struct A{
    int a, b, c;
};
queue<A> q;
int bfs(int a, int b, int c){
    visited[a][b][c] = 1;
    q.push({a,b,c});
    while(q.size()){
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();
        if(visited[0][0][0])break;
        for(int i = 0; i < 6; i++){
            int ma = max(0, a - _a[i][0]);
            int mb = max(0, b - _a[i][1]);
            int mc = max(0, c - _a[i][2]);
            if(visited[ma][mb][mc])continue;
            visited[ma][mb][mc] = visited[a][b][c] + 1;
            q.push({ma, mb, mc});
        }
    }
    return visited[0][0][0] - 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << bfs(a[0], a[1], a[2]);
    return 0;
}