#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
struct UnionFind {
    vector<int> par;
    UnionFind(int n) : par(n, -1) {}
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
        if (x == y)
            return false;
        if (par[x] > par[y])
            swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    int size(int x) {
        return -par[root(x)];
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    UnionFind uf(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        uf.merge(x, y);
    }
    map<int, vector<int>> vecs;
    for (int i = 0; i < n; i++) {
        int rt = uf.root(i);
        vecs[rt].push_back(i);
    }
    int ans = 0;
    for (auto m : vecs) {
        vector<int> vec = m.second;
        set<int> coms;
        for (int v : vec) {
            coms.insert(p[v]);
        }
        for (int v : vec) {
            if (coms.find(v) != coms.end())
                ans++;
        }
    }
    cout << ans << endl;
}