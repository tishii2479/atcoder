#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int N = 110000;
int n;
vector<int> parent(N, -1);
vector<int> depth(N, -1);
vector<vector<int>> doubling(23, vector<int>(N, 0));
int lca(int v, int u) {
    if (depth[v] < depth[u])
        swap(v, u);
    for (int i = 20; i >= 0; i--)
        if (depth[v] - depth[u] >= (1 << i))
            v = doubling[i][v];
    if (u == v)
        return u;
    for (int i = 20; i >= 0; i--)
        if (doubling[i][v] != doubling[i][u]) {
            v = doubling[i][v];
            u = doubling[i][u];
        }
    return parent[v];
}
int main() {
    int n;
    cin >> n;
    vector<int> edges[110000];
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    stack<int> st;
    st.push(0);
    depth[0] = 0;
    while (st.empty() == false) {
        int v = st.top();
        st.pop();
        for (int u : edges[v]) {
            if (depth[u] != -1)
                continue;
            parent[u] = v;
            depth[u] = depth[v] + 1;
            st.push(u);
        }
    }
    for (int i = 0; i < n; i++)
        doubling[0][i] = parent[i];
    for (int i = 0; i < 20; i++)
        for (int v = 0; v < n; v++)
            doubling[i + 1][v] = doubling[i][doubling[i][v]];
    int q;
    cin >> q;
    vector<int> res;
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        int lc = lca(u, v);
        res.push_back(depth[v] - depth[lc] + depth[u] - depth[lc] + 1);
    }
    for (int r : res)
        cout << r << endl;
}