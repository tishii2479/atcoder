#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    set<ll> st;
    for (ll i = 0; i < n; i++) st.insert(a[i]);

    vector<ll> left_sums(n + 1), sums(n + 1);
    for (ll i = 0; i < n; i++) sums[i + 1] += sums[i] + a[i];
    for (ll i = 0; i < n; i++) left_sums[i + 1] += left_sums[i] + (i % 2 != n % 2 ? a[i] : 0);

    while (q--) {
        ll x;
        cin >> x;
        ll l = 0, r = 1LL << 40;
        while (r - l > 1) {
            ll m = (r + l) / 2;

            ll left = lower_bound(a.begin(), a.end(), x - m) - a.begin();
            ll right = lower_bound(a.begin(), a.end(), x + m) - a.begin();

            bool has_right = st.find(x + m) != st.end();

            ll taka = n - right;
            ll aoki = right - left;

            if (aoki == taka) break;

            if (has_right and aoki + 1 == taka - 1) {
                break;
            }

            if (aoki > taka) {
                r = m;
            } else {
                l = m;
            }
        }

        ll m = (r + l) / 2;
        ll left = lower_bound(a.begin(), a.end(), x - m) - a.begin();
        ll right = lower_bound(a.begin(), a.end(), x + m) - a.begin();

        bool has_right = st.find(x + m) != st.end();

        ll taka = n - right;
        ll aoki = right - left;

        if (has_right and has_right and aoki + 1 == taka - 1) right++;

        ll val = sums[n] - sums[right] + left_sums[left];
        cout << val << endl;
    }
}
