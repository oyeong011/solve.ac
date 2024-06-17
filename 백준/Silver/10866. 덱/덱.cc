#include<iostream>
#include<deque>
#include<string>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    deque<int> dq;

    for(int i = 0 ; i < n ; ++i) {
        string cmd;
        cin >> cmd;

        if(cmd == "push_front") {
            int x;
            cin >> x;
            dq.push_front(x);
        } else if(cmd == "push_back") {
            int x;
            cin >> x;
            dq.push_back(x);
        } else if(cmd == "pop_front") {
            if(!dq.empty()) {
                cout << dq.front() << "\n";
                dq.pop_front();
            } else {
                cout << "-1\n";
            }
        } else if(cmd == "pop_back") {
            if(!dq.empty()) {
                cout << dq.back() << "\n";
                dq.pop_back();
            } else {
                cout << -1 << "\n";
            }
        } else if(cmd == "front") {
            if(!dq.empty()) {
                cout << dq.front() << "\n";
            } else {
                cout << -1 << "\n";
            }
        } else if(cmd == "back") {
            if(!dq.empty()) {
                cout << dq.back() << "\n";
            } else {
                cout << -1 << "\n";
            }
        } else if(cmd == "empty") {
            cout << dq.empty() << "\n";
        } else if(cmd == "size") {
            cout << dq.size() << "\n";
        }
    }

    return 0;
}