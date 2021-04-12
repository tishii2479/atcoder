#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
vector<pll> edges[110];
vector<ll> dijkstra(int s) {
    vector<ll> dist(110, INF);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (pq.empty() == false) {
        auto p = pq.top();
        pq.pop();
        ll d = p.first;
        int v = p.second;
        if (d > dist[v])
            continue;
        for (auto np : edges[v]) {
            int u = np.first;
            ll cost = np.second;
            if (dist[u] > dist[v] + cost) {
                dist[u] = dist[v] + cost;
                pq.push({dist[u], u});
            }
        }
    }
    return dist;
}
int main() {
    vector<ll> res;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;
        if (c == 0) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            auto dist = dijkstra(a);
            res.push_back((dist[b] == INF ? -1 : dist[b]));
        } else {
            int c, d, e;
            cin >> c >> d >> e;
            c--, d--;
            edges[c].push_back({d, e});
            edges[d].push_back({c, e});
        }
    }
    for (auto r : res)
        cout << r << endl;
}