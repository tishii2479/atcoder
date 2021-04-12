#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> c(n), r(n);
    for (ll i = 0; i < n; i++)
        cin >> c[i] >> r[i];
    vector<ll> edges[5100];
    for (ll i = 0; i < k; i++) {
        ll a, b;
        cin >> a >> b, a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    // dist[town][remaining] = min_dist
    vector<vector<ll>> dist(n, vector<ll>(n + 1, inf));
    dist[0][r[0]] = c[0];
    // { cost, { town, remaining } }
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    pq.push({c[0], {0, r[0]}});
    while (pq.empty() == false) {
        auto p = pq.top();
        pq.pop();
        ll cost = p.first;
        ll v = p.second.first;
        ll remain = p.second.second;
        if (remain == 0)
            continue;
        if (cost > dist[v][remain])
            continue;
        for (ll u : edges[v]) {
            if (dist[u][remain - 1] > dist[v][remain]) {
                dist[u][remain - 1] = dist[v][remain];
                pq.push({dist[u][remain - 1], {u, remain - 1}});
            }
            if (dist[u][r[u]] > dist[v][remain] + c[u]) {
                dist[u][r[u]] = dist[v][remain] + c[u];
                pq.push({dist[u][r[u]], {u, r[u]}});
            }
        }
    }
    ll ans = inf;
    for (ll i = 0; i <= n; i++)
        ans = min(ans, dist[n - 1][i]);
    cout << ans << endl;
}