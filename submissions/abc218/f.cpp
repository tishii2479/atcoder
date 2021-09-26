#include <bits/stdc++.h>
using namespace std;

const int inf = 1 << 30;
const int N = 410;
vector<int> dist(N, inf);
vector<vector<int>> edges(N);
vector<vector<int>> rev_edges(N);

void dijkstra(int s, int from = -1, int to = -1) {
    dist = vector<int>(N, inf);
    dist[s] = 0;
    using P = pair<int, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, s});
    while (pq.size()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (d > dist[v]) continue;
        for (int u : edges[v]) {
            if (d + 1 >= dist[u]) continue;
            if (v == from and u == to) continue;
            dist[u] = d + 1;
            pq.push({dist[u], u});
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> hen(m);

    for (int i = 0; i < m; i++) {
        int s, t;
        cin >> s >> t;
        s--, t--;
        edges[s].push_back(t);
        rev_edges[t].push_back(s);
        hen[i] = {s, t};
    }

    dijkstra(0);
    set<pair<int, int>> used;

    if (dist[n - 1] == inf) {
        for (int i = 0; i < m; i++) cout << -1 << endl;
        return 0;
    }

    int cur = n - 1;
    while (cur != 0) {
        for (int from : rev_edges[cur]) {
            if (dist[from] + 1 == dist[cur]) {
                used.insert({from, cur});
                cur = from;
                break;
            }
        }
    }

    int non = dist[n - 1];
    for (int i = 0; i < m; i++) {
        if (used.find(hen[i]) == used.end()) {
            cout << non << endl;
        } else {
            dijkstra(0, hen[i].first, hen[i].second);
            if (dist[n - 1] == inf)
                cout << -1 << endl;
            else
                cout << dist[n - 1] << endl;
        }
    }
}
