#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> edges;
const int inf = 1 << 30;
int n, m;

vector<int> dijkstra(int s) {
    vector<int> dist(n, inf);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while (pq.size()) {
        auto p = pq.top();
        pq.pop();
        int d = p.first;
        int v = p.second;
        if (dist[v] < d) continue;
        for (auto np : edges[v]) {
            int u = np.first, c = np.second;
            if (dist[u] > dist[v] + c) {
                dist[u] = dist[v] + c;
                pq.push({dist[u], u});
            }
        }
    }
    return dist;
}

int main() {
    cin >> n >> m;
    edges.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    auto dist1 = dijkstra(0);
    auto dist2 = dijkstra(n - 1);
    for (int i = 0; i < n; i++) cout << dist1[i] + dist2[i] << endl;
}
