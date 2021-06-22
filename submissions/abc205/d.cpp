#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    while (q--) {
        ll k;
        cin >> k;

        ll l = 0, r = 1LL << 60;
        while (r - l > 1) {
            ll m = (l + r) / 2;
            ll cnt = upper_bound(a.begin(), a.end(), m) - a.begin();
            ll val = m - cnt;
            if (val < k)
                l = m;
            else
                r = m;
        }

        cout << r << endl;
    }
}
