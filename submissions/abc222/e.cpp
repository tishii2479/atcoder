#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;

using mint = atcoder::modint998244353;
const int N = 1100;

struct Edge {
    long long to;
};
using Graph = vector<vector<Edge>>;
Graph edges(N);

/* LCA(G, root): 木 G に対する根を root として Lowest Common Ancestor を求める構造体
    query(u,v): u と v の LCA を求める。計算量 O(logn)
    前処理: O(nlogn)時間, O(nlogn)空間
*/
struct LCA {
    vector<vector<int>> parent;  // parent[k][u]:= u の 2^k 先の親
    vector<int> dist;            // root からの距離
    LCA(const Graph &G, int root = 0) { init(G, root); }

    // 初期化
    void init(const Graph &G, int root = 0) {
        int V = G.size();
        int K = 1;
        while ((1 << K) < V) K++;
        parent.assign(K, vector<int>(V, -1));
        dist.assign(V, -1);
        dfs(G, root, -1, 0);
        for (int k = 0; k + 1 < K; k++) {
            for (int v = 0; v < V; v++) {
                if (parent[k][v] < 0) {
                    parent[k + 1][v] = -1;
                } else {
                    parent[k + 1][v] = parent[k][parent[k][v]];
                }
            }
        }
    }

    // 根からの距離と1つ先の頂点を求める
    void dfs(const Graph &G, int v, int p, int d) {
        parent[0][v] = p;
        dist[v] = d;
        for (auto e : G[v]) {
            if (e.to != p) dfs(G, e.to, v, d + 1);
        }
    }

    int query(int u, int v) {
        if (dist[u] < dist[v]) swap(u, v);  // u の方が深いとする
        int K = parent.size();
        // LCA までの距離を同じにする
        for (int k = 0; k < K; k++) {
            if ((dist[u] - dist[v]) >> k & 1) {
                u = parent[k][u];
            }
        }
        // 二分探索で LCA を求める
        if (u == v) return u;
        for (int k = K - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
};

vector<int> parent(N, -1);
void dfs(int cur, int par) {
    parent[cur] = par;
    for (auto e : edges[cur]) {
        int u = e.to;
        if (u == par) continue;
        dfs(u, cur);
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[u].push_back({v});
        edges[v].push_back({u});
    }

    LCA lca(edges, 0);

    dfs(0, -1);

    map<pair<int, int>, int> mp;
    for (int i = 0; i + 1 < m; i++) {
        int lc = lca.query(a[i], a[i + 1]);
        int cur = a[i];
        while (lc != cur) {
            mp[{cur, parent[cur]}]++;
            cur = parent[cur];
        }
        cur = a[i + 1];
        while (lc != cur) {
            mp[{cur, parent[cur]}]++;
            cur = parent[cur];
        }
    }
    map<int, mint> dp;
    dp[0] = 1;
    for (auto m : mp) {
        map<int, mint> nxt;
        int cnt = m.second;
        for (auto [sum, val] : dp) {
            nxt[sum + cnt] += val;
            nxt[sum - cnt] += val;
        }
        dp = nxt;
    }

    cout << (dp[k] * mint(2).pow((n - 1) - mp.size())).val() << endl;
}
