#include<bits/stdc++.h>
using namespace std;

int mx = -4001, mn = 4001, n, sum = 0;
map<int, int> cntNum;
vector<int> v;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    
    cin >> n;
    v.reserve(n);
    
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
        mx = max(mx, x);
        mn = min(mn, x);
        cntNum[x]++;
        sum += x;
    }
    
    // 최빈값 계산 수정
    vector<int> modes;
    int maxFreq = 0;
    
    // 최대 빈도수 찾기
    for (auto [num, freq] : cntNum) {
        if (freq > maxFreq) {
            maxFreq = freq;
        }
    }
    
    // 최대 빈도수를 가진 값들 모으기
    for (auto [num, freq] : cntNum) {
        if (freq == maxFreq) {
            modes.push_back(num);
        }
    }
    
    // 정렬은 한번만
    sort(v.begin(), v.end());
    sort(modes.begin(), modes.end());  // 최빈값들 정렬
    
    // 산술평균 계산 (반올림)
    int mean = round(static_cast<double>(sum) / n);
    
    // 결과 출력
    cout << mean << '\n'                            // 산술평균
         << v[n/2] << '\n'                          // 중앙값
         << (modes.size() > 1 ? modes[1] : modes[0]) << '\n'  // 최빈값
         << mx - mn << '\n';                        // 범위
         
    return 0;
}