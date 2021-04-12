#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 29;
const int N = 1100;
const int G = N * N - 1;
vector<int> edge[N][26];
vector<pair<int, int>> edge2[N * N];
int dist[N * N];
void dijkstra(int s) {
    fill(dist, dist + N * N, inf);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while (pq.size()) {
        auto p = pq.top();
        pq.pop();
        int v = p.second;
        if (dist[v] < p.first)
            continue;
        for (auto np : edge2[p.second]) {
            int u = np.first;
            int cost = np.second;
            if (dist[u] <= dist[v] + cost)
                continue;
            dist[u] = dist[v] + cost;
            pq.push({dist[u], u});
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        a--, b--;
        c -= 'a';
        edge[a][c].push_back(b);
        edge[b][c].push_back(a);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int from = i * N + j;
            for (int c = 0; c < 26; c++)
                for (int ito : edge[i][c])
                    for (int jto : edge[j][c]) {
                        int to = ito * N + jto;
                        edge2[from].push_back({to, 2});
                    }
        }
    for (int i = 0; i < n; i++)
        edge2[i * N + i].push_back({G, 0});
    for (int i = 0; i < n; i++)
        for (int c = 0; c < 26; c++)
            for (int u : edge[i][c])
                edge2[i * N + u].push_back({G, 1});
    int start = 0 * N + (n - 1);
    dijkstra(start);
    int ans = dist[G];
    if (ans == inf)
        ans = -1;
    cout << ans << endl;
}