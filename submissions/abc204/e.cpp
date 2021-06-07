#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 110000;
const ll INF = 1LL << 60;
vector<vector<pair<int, pair<ll, ll>>>> edges(N);
vector<ll> dist(N, INF);

void dijkstra(int s = 0) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while (pq.size()) {
        auto p = pq.top();
        pq.pop();
        ll cur = p.first;
        int v = p.second;
        if (cur > dist[v]) continue;
        for (auto np : edges[v]) {
            int u = np.first;
            ll c = np.second.first, d = np.second.second;
            ll sqr = floorl(sqrtl(d));
            ll start = max(cur, sqr);
            // cout << u << " " << start << endl;
            ll t = start + d / (1 + start) + c;

            if (t < dist[u]) {
                dist[u] = t;
                pq.push({dist[u], u});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c, d;
        cin >> a >> b >> c >> d;
        a--, b--;
        edges[a].push_back({b, {c, d}});
        edges[b].push_back({a, {c, d}});
    }

    dijkstra();

    if (dist[n - 1] == INF) dist[n - 1] = -1;
    cout << dist[n - 1] << endl;
}
