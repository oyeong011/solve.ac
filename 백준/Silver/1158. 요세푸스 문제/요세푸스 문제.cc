#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;  // n: 사람 수, k: 제거할 사람의 순서
    cin >> n >> k;

    vector<int> people;  // 사람들을 저장할 벡터
    for (int j = 1; j <= n; j++) {
        people.push_back(j);  // 1부터 n까지 숫자를 벡터에 추가
    }

    int index = 0;  // 현재 제거할 사람의 위치
    bool first = true;  // 첫 번째 출력인지 확인하는 플래그

    cout << "<";

    while (!people.empty()) {  // 벡터가 비어있지 않은 동안 반복
        index += k - 1;  // k번째 사람을 찾기 위해 인덱스 이동
        index %= people.size();  // 인덱스가 벡터 크기를 넘지 않도록 조정

        if (first) {
            cout << people[index];  // 첫 번째 출력
            first = false;
        } else {
            cout << ", " << people[index];  // 이후의 출력
        }

        people.erase(people.begin() + index);  // 제거한 사람을 벡터에서 삭제
    }

    cout << ">" << endl;  // 출력 마무리

    return 0;
}
