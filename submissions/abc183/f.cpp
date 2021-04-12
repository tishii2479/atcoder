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
    UnionFind() {}
    UnionFind(int n) : par(n, -1) {}
    void init(int n) { par.assign(n, -1); }
    int root(int x) {
        if (par[x] < 0)
            return x;
        else
            return par[x] = root(par[x]);
    }
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (par[x] > par[y])
            swap(x, y);  // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    int size(int x) {
        return -par[root(x)];
    }
};
int main() {
    int n, q;
    cin >> n >> q;
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i], c[i]--;
    UnionFind uf(n);
    vector<map<int, int>> dp(n);
    for (int i = 0; i < n; i++)
        dp[i][c[i]] += 1;
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        x--, y--;
        if (t == 1) {
            if (uf.issame(x, y))
                continue;
            x = uf.root(x);
            y = uf.root(y);
            uf.merge(x, y);
            if (y == uf.root(y))
                swap(x, y);
            for (auto p : dp[y])
                dp[x][p.first] += p.second;
        } else {
            x = uf.root(x);
            if (dp[x].count(y))
                cout << dp[x][y] << endl;
            else
                cout << 0 << endl;
        }
    }
}