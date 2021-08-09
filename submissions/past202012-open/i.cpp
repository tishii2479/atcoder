#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> h(n), c(k);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < k; i++) cin >> c[i];
    for (int i = 0; i < k; i++) c[i]--;
    vector<vector<int>> edges(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (h[a] < h[b]) {
            edges[a].push_back(b);
        } else if (h[a] > h[b]) {
            edges[b].push_back(a);
        }
    }

    queue<int> q;
    const int inf = 1 << 30;
    vector<int> dist(n, inf);
    for (int i = 0; i < k; i++) {
        q.push(c[i]);
        dist[c[i]] = 0;
    }

    while (q.size()) {
        auto v = q.front();
        q.pop();
        for (int u : edges[v]) {
            if (dist[u] < inf) continue;
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }
    for (int i = 0; i < n; i++) {
        if (dist[i] == inf)
            cout << -1 << endl;
        else
            cout << dist[i] << endl;
    }
}
