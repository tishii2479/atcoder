#include <bits/stdc++.h>
using namespace std;
const int N = 251000;
const int INF = 1 << 30;
vector<vector<pair<int, int>>> edges(N);
vector<int> dist(N, INF);

int idx(int y, int x) {
    return y * 501 + x;
}

void dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while (pq.size()) {
        auto p = pq.top();
        pq.pop();
        int v = p.second;
        int d = p.first;
        if (dist[v] < d) continue;
        for (auto np : edges[v]) {
            int u = np.first;
            int cost = np.second;
            if (dist[u] > dist[v] + cost) {
                dist[u] = dist[v] + cost;
                pq.push({dist[u], u});
            }
        }
    }
}

int main() {
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c - 1; j++) {
            int a;
            cin >> a;
            edges[idx(i, j)].push_back({idx(i, j + 1), a});
            edges[idx(i, j + 1)].push_back({idx(i, j), a});
        }

    for (int i = 0; i < r - 1; i++)
        for (int j = 0; j < c; j++) {
            int b;
            cin >> b;
            edges[idx(i, j)].push_back({idx(i + 1, j), b});
        }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = 1; i - k >= 0; k++) {
                edges[idx(i, j)].push_back({idx(i - k, j), k + 1});
            }
        }
    }

    dijkstra(idx(0, 0));

    // for (int i = 0; i < N; i++) {
    //     if (dist[i] != INF)
    //         cout << i << " " << dist[i] << endl;
    // }

    cout << dist[idx(r - 1, c - 1)] << endl;
}
