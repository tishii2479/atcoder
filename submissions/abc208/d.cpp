#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n, m;
const ll INF = 1LL << 60;
vector<vector<pair<int, ll>>> edges;
vector<vector<pair<int, ll>>> inv_edges;

vector<ll> dijkstra(int s, bool inv) {
    vector<ll> dist(n, INF);
    dist[s] = 0;
    using P = pair<ll, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, s});
    while (pq.size()) {
        auto p = pq.top();
        pq.pop();
        ll d = p.first;
        int v = p.second;
        if (v > s) continue;
        if (d > dist[v]) continue;
        if (inv) {
            for (auto np : inv_edges[v]) {
                int u = np.first;
                ll cost = np.second;
                if (dist[u] > cost + dist[v]) {
                    dist[u] = cost + dist[v];
                    pq.push({dist[u], u});
                }
            }
        } else {
            for (auto np : edges[v]) {
                int u = np.first;
                ll cost = np.second;
                if (dist[u] > cost + dist[v]) {
                    dist[u] = cost + dist[v];
                    pq.push({dist[u], u});
                }
            }
        }
    }

    return dist;
}

int main() {
    cin >> n >> m;
    edges.resize(n), inv_edges.resize(n);
    vector<vector<ll>> dist(n, vector<ll>(n, INF));

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edges[a].push_back({b, c});
        inv_edges[b].push_back({a, c});
        dist[a][b] = c;
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) cout << dist[i][j] << " ";
    //     cout << endl;
    // }

    ll ans = 0;

    for (int k = 0; k < n; k++) {
        vector<ll> dist_to = dijkstra(k, false);
        vector<ll> dist_from = dijkstra(k, true);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (dist_from[i] + dist_to[j] < dist[i][j]) dist[i][j] = dist_from[i] + dist_to[j];
                if (dist[i][j] == INF) continue;
                ans += dist[i][j];
                // cout << k << " " << i << " " << j << " " << ans << endl;
            }
        }
    }
    cout << ans << endl;
}
