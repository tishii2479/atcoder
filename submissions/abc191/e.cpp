#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
vector<pll> edges[2100];
int bfs(int s) {
    vector<ll> dist(2100, INF);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    for (pll p : edges[s]) {
        int u = p.first;
        ll cost = p.second;
        if (u == s)
            continue;
        if (dist[u] > dist[s] + cost) {
            dist[u] = dist[s] + cost;
            q.push(u);
        }
    }
    dist[s] = INF;
    for (pll p : edges[s]) {
        int u = p.first;
        ll cost = p.second;
        if (u != s)
            continue;
        dist[s] = min(dist[s], cost);
    }
    while (q.empty() == false) {
        int v = q.front();
        q.pop();
        for (pll p : edges[v]) {
            int u = p.first;
            ll cost = p.second;
            if (dist[u] > dist[v] + cost) {
                dist[u] = dist[v] + cost;
                q.push(u);
            }
        }
    }
    if (dist[s] == INF)
        return -1;
    return dist[s];
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edges[a].push_back({b, c});
    }
    for (int i = 0; i < n; i++) {
        cout << bfs(i) << endl;
    }
}