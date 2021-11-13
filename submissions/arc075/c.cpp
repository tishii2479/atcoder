#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;

int main() {
    using ll = long long;
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1, 0);
    for (ll i = 0; i < n; i++) cin >> a[i];

    vector<ll> b(n + 1);
    ll sum = 0;
    for (ll i = 0; i <= n; i++) {
        b[i] = sum - i * k;
        sum += a[i];
    }

    set<ll> st;
    for (ll e : b) st.insert(e);
    map<ll, ll> mp;
    ll cur = 0;
    for (ll e : st) mp[e] = cur++;
    atcoder::fenwick_tree<ll> fen(n + 1);
    ll ans = 0;
    for (ll i = 0; i <= n; i++) {
        ll val = mp[b[i]];
        ans += fen.sum(0, val + 1);
        fen.add(val, 1);
    }
    cout << ans << endl;
}
