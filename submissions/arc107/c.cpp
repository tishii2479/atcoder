#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
#define each(i, mp) for (auto &i : mp)
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
// const int MOD = 1000000007;
const int MOD = 998244353;
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
ll kaijo(int n) {
    ll res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
        res %= MOD;
    }
    return res;
}
int main() {
    int n, K;
    cin >> n >> K;
    int data[55][55];
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> data[y][x];
        }
    }
    UnionFind ufv(n);
    UnionFind ufh(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool ok = true;
            for (int k = 0; k < n; k++) {
                if (data[i][k] + data[j][k] > K)
                    ok = false;
            }
            if (ok) {
                ufh.merge(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool ok = true;
            for (int k = 0; k < n; k++) {
                if (data[k][i] + data[k][j] > K)
                    ok = false;
            }
            if (ok) {
                ufv.merge(i, j);
            }
        }
    }
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        if (i == ufv.root(i)) {
            ans *= kaijo(ufv.size(i));
            ans %= MOD;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == ufh.root(i)) {
            ans *= kaijo(ufh.size(i));
            ans %= MOD;
        }
    }
    cout << ans << endl;
}