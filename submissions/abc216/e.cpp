#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end(), greater<ll>());

    vector<ll> sums(n + 1, 0);
    for (int i = 0; i < n; i++) sums[i + 1] += sums[i] + a[i];

    ll l = 0, r = 1LL << 40;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += max(0LL, a[i] - m);
        }

        if (cnt > k) {
            l = m;
        } else {
            r = m;
        }
    }

    ll use = r;
    ll ans = 0;
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] - use <= 0) continue;
        cnt += max(0LL, a[i] - use);
        ans += a[i] * (a[i] + 1) / 2 - use * (use + 1) / 2;
    }

    ans += min(n, (k - cnt)) * r;

    cout << ans << endl;
}
