#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(b.begin(), b.end());

    ll ans = 1LL << 60;

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        ans = min(ans, abs(a[i] - *it));
        if (it != b.begin()) {
            it--;
            ans = min(ans, abs(a[i] - *it));
        }
    }

    cout << ans << endl;
}
