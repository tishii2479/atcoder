#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
struct S {
    ll to, cost, span;
};
vector<S> edges[110000];
vector<ll> dist(110000, INF);
void bfs(int st) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, st});
    while (pq.empty() == false) {
        pll p = pq.top();
        pq.pop();
        ll d = p.first;
        ll v = p.second;
        if (d > dist[v])
            continue;
        for (auto s : edges[v]) {
            ll go = (d + s.span - 1) / s.span * s.span;
            if (dist[s.to] > go + s.cost) {
                dist[s.to] = go + s.cost;
                pq.push({dist[s.to], s.to});
            }
        }
    }
}
int main() {
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    x--, y--;
    for (int i = 0; i < m; i++) {
        ll a, b, t, k;
        cin >> a >> b >> t >> k;
        a--, b--;
        edges[a].push_back({b, t, k});
        edges[b].push_back({a, t, k});
    }
    dist[x] = 0;
    bfs(x);
    if (dist[y] == INF)
        cout << -1 << endl;
    else
        cout << dist[y] << endl;
}