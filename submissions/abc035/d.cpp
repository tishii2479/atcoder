#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    const ll N = 110000;
    const ll INF = 1LL << 60;
    vector<pair<ll, ll>> edges[N];
    vector<pair<ll, ll>> edges2[N];
    vector<ll> dist(N, INF);
    vector<ll> dist2(N, INF);
    ll n, m, t;
    cin >> n >> m >> t;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edges[a].push_back({b, c});
        edges2[b].push_back({a, c});
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
        pq;
    pq.push({0, 0});
    dist[0] = 0;
    while (pq.size()) {
        auto p = pq.top();
        pq.pop();
        ll d = p.first;
        ll v = p.second;
        if (d > dist[v]) continue;
        for (auto np : edges[p.second]) {
            ll u = np.first, cost = np.second;
            if (dist[u] <= dist[v] + cost) continue;
            dist[u] = dist[v] + cost;
            pq.push({dist[u], u});
        }
    }
    pq.push({0, 0});
    dist2[0] = 0;
    while (pq.size()) {
        auto p = pq.top();
        pq.pop();
        ll d = p.first;
        ll v = p.second;
        if (d > dist2[v]) continue;
        for (auto np : edges2[p.second]) {
            ll u = np.first, cost = np.second;
            if (dist2[u] <= dist2[v] + cost) continue;
            dist2[u] = dist2[v] + cost;
            pq.push({dist2[u], u});
        }
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        if (dist[i] == INF or dist2[i] == INF) continue;
        ans = max(ans, (t - dist[i] - dist2[i]) * a[i]);
    }
    cout << ans << endl;
}