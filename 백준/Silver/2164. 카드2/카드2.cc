#include <iostream>
#include <deque>

using namespace std;

int main() {
    int N;
    cin >> N;

    deque<int> q;
    for (int i = 1; i <= N; ++i) {
        q.push_back(i);
    }

    while (q.size() > 1) {
        q.pop_front();  // 제일 위의 카드를 버림
        q.push_back(q.front());  // 그 다음 제일 위의 카드를 제일 아래로 옮김
        q.pop_front();  // 다시 제일 위의 카드를 제거
    }

    cout << q.front() << "\n";  // 마지막 남은 카드 출력

    return 0;
}
