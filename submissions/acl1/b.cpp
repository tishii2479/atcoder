#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

int main() {
    using ll = long long;
    const ll INF = 1LL << 60;
    ll n;
    cin >> n;
    n *= 2;
    ll ans = INF;

    for (ll x = 1; x * x <= n; x++) {
        if (n % x == 0) {
            for (int i = 0; i < 2; i++) {
                ll y = n / x;
                vector<ll> r(2), m(2);
                r[0] = 0 - i, r[1] = -1 + i;
                m[0] = x, m[1] = y;
                auto p = crt(r, m);
                if (p.first > 0) ans = min(ans, p.first);
            }
        }
    }
    cout << ans << endl;
}
