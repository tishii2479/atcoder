#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
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
    int n;
    cin >> n;
    UnionFind uf(400005);
    vector<int> edge(400005, 0);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        uf.merge(a, b);
    }
    int ans = 0;
    for (int i = 0; i < 400005; i++) {
        if (uf.root(i) == i) {
            ans += min(uf.size(i), uf.edge_cnt(i));
            // cout << uf.edge_cnt(i) << endl;
        }
    }
    cout << ans << endl;
}