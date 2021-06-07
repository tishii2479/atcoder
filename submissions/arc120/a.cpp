#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> sums(n);
    for (int i = 0; i + 1 < n; i++) sums[i + 1] += a[i] + sums[i];

    ll mx = 0;
    ll cur = 0;
    ll sum = 0;

    for (int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
        sum += a[i];
        // cout << sum << " " << cur << " " << mx << endl;
        ll ans = mx * (i + 1) + sum + cur;
        cout << ans << endl;
        cur += sums[i];
        cur += a[i];
    }
}
