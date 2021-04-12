#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
ll pow10[10];
int main() {
    ll k;
    string s, t;
    cin >> k;
    cin >> s >> t;
    pow10[0] = 1;
    for (ll i = 0; i < 9; i++)
        pow10[i + 1] = pow10[i] * 10;
    vector<ll> scnt(10, 0);
    vector<ll> tcnt(10, 0);
    vector<ll> total(10, k);
    for (ll i = 0; i < 4; i++) {
        scnt[s[i] - '0']++;
        total[s[i] - '0']--;
    }
    for (ll i = 0; i < 4; i++) {
        tcnt[t[i] - '0']++;
        total[t[i] - '0']--;
    }
    double ans = 0;
    for (ll i = 1; i <= 9; i++)
        for (ll j = 1; j <= 9; j++) {
            vector<ll> sc = scnt;
            vector<ll> tc = tcnt;
            if (i == j) {
                if (total[i] < 2)
                    continue;
            } else if (total[i] < 1 or total[j] < 1) {
                continue;
            }
            sc[i]++;
            tc[j]++;
            ll ts = 0;
            ll tt = 0;
            for (ll k = 1; k < 10; k++)
                ts += k * pow10[sc[k]];
            for (ll k = 1; k < 10; k++)
                tt += k * pow10[tc[k]];
            if (ts > tt) {
                double p;
                ll all = (k * 9 - 8) * (k * 9 - 9);
                if (i == j) {
                    p = (double)total[i] * (total[i] - 1) / all;
                } else {
                    p = (double)total[i] * total[j] / all;
                }
                ans += p;
            }
        }
    printf("%.15lf\n", ans);
}