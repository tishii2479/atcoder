#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> sums(n + 1);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sums[i + 1] = sums[i] + a[i];
        } else {
            sums[i + 1] = sums[i] - a[i];
        }
    }

    map<ll, ll> mp;
    for (int i = 0; i <= n; i++) mp[sums[i]]++;

    ll ans = 0;

    for (auto m : mp) ans += (m.second - 1) * m.second / 2;

    cout << ans << endl;
}
