#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    ll n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    ll mx = *max_element(a.begin(), a.end());

    ll need = 0;
    for (ll i = 0; i < n; i++) need += mx - a[i];

    if (k >= need) {
        k -= need;
        ll cur = mx;
        cur += k / n;
        cout << cur << endl;
        return 0;
    }

    const ll N = mx;
    vector<ll> sums(610000, 0);
    for (int i = 0; i < n; i++) sums[a[i]]++;
    for (int i = 0; i + 1 < 610000; i++) sums[i + 1] += sums[i];

    for (ll i = N; i >= 0; i--) {
        if (need <= k) {
            cout << i << endl;
            return 0;
        }

        assert(i > 0);

        for (ll j = 1; i * j < 610000; j++) {
            need -= (sums[(i - 1) * j] - sums[max(0LL, i * (j - 1))]) * j;
            need += (sums[i * j] - sums[(i - 1) * j]) * (i - 1 - j);
        }
    }
    assert(false);
}
