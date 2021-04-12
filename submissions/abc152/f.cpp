#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m;
// to, idx
vector<vector<pair<ll, ll>>> edges;
// u, v
vector<pair<ll, ll>> uv;
bool dfs(ll v, ll par, ll tar, ll &path) {
    if (v == tar) {
        path = 0;
        return true;
    }
    for (auto p : edges[v]) {
        if (p.first == par)
            continue;
        if (dfs(p.first, v, tar, path)) {
            path |= (1LL << p.second);
            return true;
        }
    }
    return false;
}
int main() {
    cin >> n;
    edges.assign(n, {});
    for (ll i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back({b, i});
        edges[b].push_back({a, i});
    }
    cin >> m;
    uv.resize(m);
    for (ll i = 0; i < m; i++) {
        cin >> uv[i].first >> uv[i].second;
        uv[i].first--, uv[i].second--;
    }
    vector<ll> paths(m, 0);
    for (ll i = 0; i < m; i++)
        dfs(uv[i].first, -1, uv[i].second, paths[i]);
    ll ans = 0;
    for (ll bit = 0; bit < (1LL << m); bit++) {
        ll all = 0;
        for (ll i = 0; i < m; i++)
            if (bit & (1LL << i))
                all |= paths[i];
        ll rest = n - 1 - __builtin_popcountl(all);
        if (__builtin_popcountl(bit) % 2 == 0)
            ans += 1LL << rest;
        else
            ans -= 1LL << rest;
    }
    cout << ans << endl;
}