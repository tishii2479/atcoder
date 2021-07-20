#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    string s;
    ll k;
    cin >> s >> k;

    const int N = s.length();
    const ll INF = k + 1;

    map<ll, ll> dp;
    ll product = 1;
    for (int i = 0; i < N; i++) {
        ll v = s[i] - '0';
        map<ll, ll> nxt;

        // less -> less
        for (auto m : dp) {
            for (int d = 0; d < 10; d++) {
                ll val = m.first * d;
                nxt[min(INF, val)] += m.second;
            }
        }

        // equal -> less
        for (int d = 0; d < v; d++) {
            if (i == 0 and d == 0) continue;
            ll val = product * d;
            nxt[min(INF, val)] += 1;
        }

        // equal -> equal
        product *= v;

        if (i > 0) {
            for (int d = 1; d < 10; d++) {
                ll val = d;
                nxt[min(INF, val)] += 1;
            }
        }
        dp = nxt;
    }

    ll ans = 0;

    for (auto m : dp)
        if (m.first <= k) ans += m.second;
    if (product <= k) ans++;

    cout << ans << endl;
}
