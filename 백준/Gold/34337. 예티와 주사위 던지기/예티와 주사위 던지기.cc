#include <iostream>
#include <algorithm>
using namespace std;

int dice[5];
int temp[5];

int calc_score() {
    int cnt[7] = {0};
    for (int i = 0; i < 5; i++)
        cnt[temp[i]]++;

    int best = 0;
    for (int i = 1; i <= 6; i++)
        best = max(best, cnt[i] * i);
    for (int i = 1; i <= 6; i++)
        if (cnt[i] == 5) best = 50;

    return best;
}

long long solve(int idx, int reroll[], int reroll_cnt) {
    if (idx == reroll_cnt) {
        return calc_score();
    }

    long long sum = 0;
    int pos = reroll[idx];
    for (int d = 1; d <= 6; d++) {
        temp[pos] = d;
        sum += solve(idx + 1, reroll, reroll_cnt);
    }
    return sum;
}

int main() {
    for (int i = 0; i < 5; i++) cin >> dice[i];

    long long ans = 0;

    for (int mask = 0; mask < 32; mask++) {
        for (int i = 0; i < 5; i++) temp[i] = dice[i];

        int reroll[5], reroll_cnt = 0;
        for (int i = 0; i < 5; i++) {
            if (mask & (1 << i))
                reroll[reroll_cnt++] = i;
        }

        long long total = solve(0, reroll, reroll_cnt);
        for (int i = 0; i < 5 - reroll_cnt; i++)
            total *= 6;

        ans = max(ans, total);
    }

    cout << ans << endl;
    return 0;
}
