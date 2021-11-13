#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    ll n;
    cin >> n;

    vector<ll> t(n);
    vector<vector<ll>> edges(n);

    for (ll i = 0; i < n; i++) {
        cin >> t[i];
        ll k;
        cin >> k;
        for (ll j = 0; j < k; j++) {
            ll a;
            cin >> a;
            a--;
            edges[i].push_back(a);
        }
    }

    ll ans = 0;

    set<ll> need;
    need.insert(n - 1);
    for (ll i = n - 1; i >= 0; i--) {
        if (need.find(i) != need.end())
            ans += t[i];
        else {
            continue;
        }
        for (ll u : edges[i]) need.insert(u);
    }

    cout << ans << endl;
}
