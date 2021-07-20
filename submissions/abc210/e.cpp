#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> ca(m);

    for (int i = 0; i < m; i++) {
        cin >> ca[i].second >> ca[i].first;
    }

    sort(ca.begin(), ca.end());

    ll ans = 0;
    ll need = n - 1;
    ll cur = n;

    for (int i = 0; i < m; i++) {
        if (need == 0) break;
        ll c = ca[i].first, a = ca[i].second;
        a %= n;

        ll gc = gcd(a, cur);

        ll able = (cur / gc - 1) * gc;
        ll use = min(able, need);
        need -= use;
        ans += use * c;

        cur = gc;
    }

    if (need > 0) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
