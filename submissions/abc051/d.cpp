#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
vector<vector<int>> cost(110, vector<int>(110, inf));
vector<pint> edges[1100];
bool used[1100][1100];
int n, m;
void dijkstra(int s) {
    vector<int> dist(1100, inf);
    // dist, ind
    priority_queue<pint, vector<pint>, greater<pint>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (pq.empty() == false) {
        auto p = pq.top();
        pq.pop();
        int d = p.first;
        int v = p.second;
        // cout << v << endl;
        if (d > dist[v])
            continue;
        for (pint np : edges[v]) {
            int u = np.first;
            int cost = np.second;
            if (dist[u] > dist[v] + cost) {
                dist[u] = dist[v] + cost;
                pq.push({dist[u], u});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(dist[j] - dist[i]) == cost[i][j]) {
                // cout << i << " " << j << endl;
                used[i][j] = true;
            }
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
        cost[a][b] = c;
        cost[b][a] = c;
    }
    for (int s = 0; s < n; s++) {
        dijkstra(s);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (used[i][j] == false and cost[i][j] < inf)
                cnt++;
    cout << cnt << endl;
}