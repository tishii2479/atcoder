#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
struct Edge {
    ll to, a, b;
};
int main() {
    ll n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;
    vector<Edge> edges[110000];
    for (int i = 0; i < m; i++) {
        ll u, v, a, b;
        cin >> u >> v >> a >> b;
        u--, v--;
        edges[u].push_back({v, a, b});
        edges[v].push_back({u, a, b});
    }
    vector<ll> s_dist(n, INF);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    s_dist[s] = 0;
    pq.push({0, s});
    while (pq.empty() == false) {
        auto p = pq.top();
        pq.pop();
        ll d = p.first;
        ll v = p.second;
        if (d > s_dist[v])
            continue;
        for (auto s : edges[v]) {
            ll cost = s.a;
            ll to = s.to;
            if (d + cost < s_dist[to]) {
                s_dist[to] = d + cost;
                pq.push({s_dist[to], to});
            }
        }
    }
    vector<ll> t_dist(n, INF);
    t_dist[t] = 0;
    pq.push({0, t});
    while (pq.empty() == false) {
        auto p = pq.top();
        pq.pop();
        ll d = p.first;
        ll v = p.second;
        if (d > t_dist[v])
            continue;
        for (auto s : edges[v]) {
            ll cost = s.b;
            ll to = s.to;
            if (d + cost < t_dist[to]) {
                t_dist[to] = d + cost;
                pq.push({t_dist[to], to});
            }
        }
    }
    vector<ll> res(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i + 1 << " " << s_dist[i] << " " << t_dist[i] << endl;
    // }
    ll cur = INF;
    for (ll i = 0; i < n; i++) {
        cur = min(cur, s_dist[n - i - 1] + t_dist[n - i - 1]);
        res[i] = cur;
    }
    reverse(res.begin(), res.end());
    for (ll r : res)
        cout << 1000000000000000LL - r << endl;
}