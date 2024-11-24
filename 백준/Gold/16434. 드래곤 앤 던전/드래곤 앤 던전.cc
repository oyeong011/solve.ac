#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, atk, q, w, e, lo, hi ,ret;
struct Mon {
    ll t; ll a; ll h;
} room[123459];

bool go(ll hp) {
    ll maxHp = hp;
    ll lcAtk = atk;
    for (int i = 0; i < n; i++) {
        if (room[i].t == 1) {
            if (lcAtk >= room[i].h)continue;
            hp -= (room[i].h / lcAtk) * room[i].a;
            if (room[i].h % lcAtk == 0) hp += room[i].a;
        } else {
            hp += room[i].h;
            if (hp > maxHp) hp = maxHp;
            lcAtk += room[i].a;
        }
        if (hp <= 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> atk;


    for (int i = 0; i < n; i++) {
        cin >> q >> w >> e;
        room[i].t = q; room[i].a = w; room[i].h = e;
    }
    lo = 0; hi = 1e18 + 4;

    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (go(mid)) {
            hi = mid - 1;
            ret = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << ret << '\n';

}