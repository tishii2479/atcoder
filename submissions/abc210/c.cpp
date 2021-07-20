#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    ll n, k;
    cin >> n >> k;
    vector<ll> c(n);
    map<ll, ll> mp;

    for (ll i = 0; i < n; i++) {
        cin >> c[i];
    }

    for (ll i = 0; i < k; i++) mp[c[i]]++;

    ll ans = mp.size();
    ll cur = mp.size();

    for (ll i = k; i < n; i++) {
        if (c[i] != c[i - k]) {
            if (mp[c[i - k]] == 1) {
                cur--;
            }
            if (mp[c[i]] == 0) {
                cur++;
            }
        }
        mp[c[i]]++;
        mp[c[i - k]]--;

        ans = max(ans, cur);
    }

    cout << ans << endl;
}
