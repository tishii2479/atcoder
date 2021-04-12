#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define each(i, mp) for (auto &i : mp)
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repd(i, n) for (ll i = n - 1; i >= 0; i--)
#define MOD 1000000007
// #define MOD 998244353
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
struct UnionFind {
    vector<int> par;
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
const ll INF = 1LL << 60;
const int inf = 1 << 29;
int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    UnionFind uf(n);
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        uf.merge(x, y);
    }
    vector<ll> sa(n, 0);
    vector<ll> sb(n, 0);
    rep(i, n) {
        int r = uf.root(i);
        sa[r] += a[i];
        sb[r] += b[i];
    }
    bool res = true;
    rep(i, n) {
        int r = uf.root(i);
        if (sa[r] != sb[r])
            res = false;
    }
    if (res)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}