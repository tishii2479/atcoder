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
        if (par[x] < par[y])
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
    vector<pint> ab(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        ab[i] = {a, b};
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        UnionFind uf(n);
        for (int j = 0; j < m; j++) {
            if (j == i)
                continue;
            uf.merge(ab[j].first, ab[j].second);
        }
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (j == uf.root(j))
                cnt++;
        }
        if (cnt > 1)
            ans++;
    }
    cout << ans << endl;
}