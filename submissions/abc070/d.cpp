#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
vector<pll> edges[110000];
vector<ll> dist(110000, INF);
void dijkstra(ll s) {
    dist[s] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, s});
    while (pq.empty() == false) {
        auto p = pq.top();
        pq.pop();
        ll d = p.first;
        ll v = p.second;
        if (dist[v] < d)
            continue;
        for (auto p : edges[v]) {
            int u = p.first;
            ll cost = p.second;
            if (dist[u] > dist[v] + cost) {
                dist[u] = dist[v] + cost;
                pq.push({dist[u], u});
            }
        }
    }
}
int main() {
    ll n;
    cin >> n;
    for (ll i = 0; i < n - 1; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    ll q, k;
    cin >> q >> k;
    k--;
    dijkstra(k);
    vector<ll> res(q);
    for (ll i = 0; i < q; i++) {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        res[i] = dist[x] + dist[y];
    }
    for (ll r : res) {
        cout << r << endl;
    }
}