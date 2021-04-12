#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
ll solve() {
    ll x, y, p, q;
    cin >> x >> y >> p >> q;
    ll ans = INF;
    for (ll i = x; i < x + y; i++) {
        auto res = crt({i, p}, {2 * (x + y), p + q});
        if (res.first > 0)
            ans = min(ans, res.first);
    }
    for (ll i = p; i < p + q; i++) {
        auto res = crt({x, i}, {2 * (x + y), p + q});
        if (res.first > 0)
            ans = min(ans, res.first);
    }
    return ans;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll res = solve();
        if (res == INF)
            cout << "infinity" << endl;
        else
            cout << res << endl;
    }
}