#include<iostream>
#include<stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x;
    cin >> x;

    stack<int> s;

    while (x--) {
        string cmd;
        cin >> cmd;
        if(cmd == "push") {
            int num;
            cin >> num;
            s.push(num);
        } else if(cmd == "pop") {
            if(!s.empty()) {
                cout << s.top() << "\n";
                s.pop();
            } else {
                cout << "-1\n";
            }
        } else if(cmd == "top") {
            if(!s.empty()) {
                cout << s.top() << "\n";
            } else {
                cout << "-1\n";
            }
        } else if(cmd == "size") {
            cout << s.size() << "\n";
        } else if(cmd == "empty") {
            cout << s.empty() << "\n";
        }
    }

    return 0;
}