#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
struct UnionFind {
    vector<ll> par;
    UnionFind(ll n) : par(n, -1) {}
    ll root(ll x) {
        if (par[x] < 0)
            return x;
        else
            return par[x] = root(par[x]);
    }
    bool same(ll x, ll y) {
        return root(x) == root(y);
    }
    bool merge(ll x, ll y) {
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
    ll size(int x) {
        return -par[root(x)];
    }
};
int main() {
    ll n, m;
    cin >> n >> m;
    vector<pll> ab(m);
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        ab[i] = {a, b};
    }
    UnionFind uf(n);
    ll now = n * (n - 1) / 2;
    vector<ll> res(m);
    for (int i = m - 1; i >= 0; i--) {
        res[i] = now;
        ll a = ab[i].first;
        ll b = ab[i].second;
        if (uf.same(a, b))
            continue;
        ll sa = uf.size(a);
        ll sb = uf.size(b);
        now -= sa * sb;
        uf.merge(a, b);
    }
    for (int i = 0; i < m; i++) {
        cout << res[i] << endl;
    }
}