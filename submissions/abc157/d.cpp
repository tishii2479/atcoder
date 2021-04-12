#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
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
const ll INF = 1LL << 60;
const int inf = 1 << 29;
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
    int n, m, k;
    cin >> n >> m >> k;
    int a, b;
    UnionFind uf(n);
    vector<set<int>> fri(n, set<int>());
    vector<set<int>> block(n, set<int>());
    rep(i, m) {
        cin >> a;
        cin >> b;
        uf.merge(a - 1, b - 1);
        block[a - 1].insert(b - 1);
        block[b - 1].insert(a - 1);
    }
    rep(i, k) {
        cin >> a;
        cin >> b;
        if (uf.same(a - 1, b - 1) == false)
            continue;
        block[a - 1].insert(b - 1);
        block[b - 1].insert(a - 1);
    }
    rep(i, n) {
        cout << uf.size(i) - 1 - block[i].size() << " ";
    }
}