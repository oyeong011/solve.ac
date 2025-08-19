#include<bits/stdc++.h>
using namespace std;

int main() {
    int car[4] = {0,}, time[101] = {0,};
    int sum = 0;
    cin >> car[1] >> car[2] >> car[3];

    for (int i = 0; i < 3; i++) {
        int start, end;
        cin >> start >> end;
        for (int j = start; j < end; j++) {
            time[j]++;
        }
    }

    for (int i = 0; i < 101; i++) {
        sum += car[time[i]] * time[i];
    }

    cout << sum;
}
