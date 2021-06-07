#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    ll n, k;
    cin >> n >> k;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        mp[a] += b;
    }

    ll cur = 0;
    for (auto m : mp) {
        ll vi = m.first, plus = m.second;
        if (vi - cur > k) {
            cout << cur + k << endl;
            return 0;
        }
        k -= vi - cur;
        k += m.second;
        cur = vi;
    }
    cur += k;
    cout << cur << endl;
}
