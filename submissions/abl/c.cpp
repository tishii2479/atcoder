#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
struct UnionFind {
    vector<int> par;
    vector<int> edge;
    UnionFind(int n) : par(n, -1), edge(n, 0) {}
    int root(int x) {
        if (par[x] < 0)
            return x;
        else
            return par[x] = root(par[x]);
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) {
            edge[x]++;
            return false;
        }
        if (par[x] > par[y])
            swap(x, y);
        par[x] += par[y];
        par[y] = x;
        edge[x] += edge[y] + 1;
        return true;
    }
    int size(int x) {
        return -par[root(x)];
    }
    int edge_cnt(int x) {
        return edge[x];
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        uf.merge(a, b);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (uf.root(i) == i)
            ans++;
    }
    cout << ans - 1 << endl;
}