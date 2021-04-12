#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Edge {
    ll from, to, cost;
};
int main() {
    const ll INF = 1LL << 60;
    ll n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edges[i] = {a, b, -c};
    }
    vector<ll> dist(n, INF);
    dist[0] = 0;
    for (int i = 0; i < 2 * n; i++)
        for (int j = 0; j < m; j++) {
            auto edge = edges[j];
            if (dist[edge.to] > dist[edge.from] + edge.cost) {
                dist[edge.to] = dist[edge.from] + edge.cost;
                if (i >= n - 1 and edge.to == n - 1) {
                    cout << "inf" << endl;
                    return 0;
                }
            }
        }
    // for (int i = 0; i < n; i++)
    //     cout << dist[i] << endl;
    cout << -dist[n - 1] << endl;
}