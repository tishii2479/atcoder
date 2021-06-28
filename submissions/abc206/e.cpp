#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    const ll N = 1e6 + 10;
    ll l, r;
    cin >> l >> r;
    vector<ll> cnt(N, 0);

    ll ans = 0;
    for (ll g = 1e6; g >= 2; g--) {
        ll xk = r / g - (l - 1) / g;
        ll val = xk * xk;
        for (ll i = 2; i * g < N; i++) {
            val -= cnt[i * g];
        }

        cnt[g] = val;

        if (max(2LL, l) <= g and g <= r)
            val -= 2 * xk - 1;

        ans += val;
    }

    cout << ans << endl;
}
