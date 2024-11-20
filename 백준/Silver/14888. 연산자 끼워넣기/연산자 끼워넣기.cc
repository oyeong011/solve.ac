#include<bits/stdc++.h>
using namespace std;
int n, rsp[4], num[14], retMin = INT32_MAX, retMax = -INT32_MIN;
int cal(deque<int> q) {
    int sum = num[0];
    for (int i = 0; i < n-1 ; i++) {
        if (q.front() == 0){ sum += num[i+1], q.pop_front();}
        else if (q.front() == 1){ sum -= num[i+1], q.pop_front();}
        else if (q.front() == 2){ sum *= num[i+1], q.pop_front();}
        else if (q.front() == 3){ sum /= num[i+1], q.pop_front();}
    }
    return sum;
}
void go(int depth, deque<int> q) {
    if (depth == n-1) {
        int a = cal(q);
        retMin = min(retMin, a);
        retMax = max(retMax, a);
        q.clear();
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (rsp[i] == 0)continue;
        q.push_back(i), rsp[i]--;
        go(depth+1, q);
        q.pop_back(), rsp[i]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> rsp[i];
    }

    deque<int> dq;
    go(0, dq);

    cout << retMax << "\n";
    cout << retMin << "\n";


}