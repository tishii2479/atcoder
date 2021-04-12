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
    int n;
    cin >> n;
    vector<pll> xi(n);
    vector<pll> yi(n);
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        xi[i] = {x, i};
        yi[i] = {y, i};
    }
    sort(xi.begin(), xi.end());
    sort(yi.begin(), yi.end());
    vector<pair<ll, pair<int, int>>> dx(n - 1);
    vector<pair<ll, pair<int, int>>> dy(n - 1);
    for (int i = 0; i < n - 1; i++) {
        dx[i] = {abs(xi[i].first - xi[i + 1].first), {xi[i].second, xi[i + 1].second}};
        dy[i] = {abs(yi[i].first - yi[i + 1].first), {yi[i].second, yi[i + 1].second}};
    }
    sort(dx.begin(), dx.end());
    sort(dy.begin(), dy.end());
    int cnt = 0;
    ll cost = 0;
    UnionFind uf(n);
    int xnext = 0;
    int ynext = 0;
    // for (int i = 0; i < n - 1; i++)
    // {
    //     cout << i << endl;
    //     cout << dx[i].first << " " << dx[i].second.first << " " << dx[i].second.second << endl;
    //     cout << dy[i].first << " " << dy[i].second.first << " " << dy[i].second.second << endl;
    // }
    while (cnt < n - 1) {
        if (xnext < n - 1 and dx[xnext] < dy[ynext]) {
            int i = dx[xnext].second.first;
            int j = dx[xnext].second.second;
            if (!uf.same(i, j)) {
                uf.merge(i, j);
                cost += dx[xnext].first;
                cnt++;
            }
            xnext++;
        } else {
            int i = dy[ynext].second.first;
            int j = dy[ynext].second.second;
            if (!uf.same(i, j)) {
                uf.merge(i, j);
                cost += dy[ynext].first;
                cnt++;
            }
            ynext++;
        }
        // cout << cnt << " " << cost << " " << xnext << " " << ynext << endl;
    }
    cout << cost << endl;
}