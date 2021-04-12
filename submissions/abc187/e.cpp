#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
ll cost[210000];
ll res[210000];
ll depth[210000];
ll n;
vector<pint> line;
vector<int> edges[210000];
// ima , parent, fukasa
void dfs(int v, int p, ll d) {
    for (int u : edges[v]) {
        if (u == p)
            continue;
        depth[u] = d + 1;
        dfs(u, v, d + 1);
    }
}
// ima, parent, nowcost
void resdfs(int v, int p, ll c) {
    c += cost[v];
    // cout << v << " " << c << endl;
    res[v] = c;
    for (int u : edges[v]) {
        if (u == p)
            continue;
        resdfs(u, v, c);
    }
}
int main() {
    ll a, b;
    cin >> n;
    for (ll i = 0; i < n - 1; i++) {
        cin >> a >> b;
        a--;
        b--;
        line.push_back({a, b});
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    // fukasa
    depth[0] = 0;
    dfs(0, -1, 0);
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++) {
        ll t, e, x;
        cin >> t >> e >> x;
        e--;
        ll a = line[e].first;
        ll b = line[e].second;
        if (t == 1) {
            // a -> b
            if (depth[a] > depth[b]) {
                cost[a] += x;
            } else {
                cost[0] += x;
                cost[b] -= x;
            }
        } else {
            // b -> a
            if (depth[a] > depth[b]) {
                cost[0] += x;
                cost[a] -= x;
            } else {
                cost[b] += x;
            }
        }
    }
    resdfs(0, -1, 0);
    for (ll i = 0; i < n; i++) {
        cout << res[i] << endl;
    }
}