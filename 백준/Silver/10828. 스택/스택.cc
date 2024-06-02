
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<int> stack;
    int n;
    cin >> n;

    while(n--) {
        string command;
        cin >> command;

        if(command == "push") {
            int x;
            cin >> x;
            stack.push(x);
        } else if (command == "pop") {
            if(stack.empty()) {
                cout << -1 << endl;
            } else {
                cout << stack.top() << endl;
                stack.pop();
            }
        } else if(command == "size") {
            cout << stack.size() << endl;
        } else if (command == "empty") {
            cout << (stack.empty() ? 1 : 0) << endl;
        } else if(command == "top") {
            cout << (stack.empty() ? -1 : stack.top()) << endl;
        }
    }
}

