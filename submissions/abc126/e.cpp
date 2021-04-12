#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
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
    vector<int> par;             // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    UnionFind(int N) : par(N) {  //最初は全てが根であるとして初期化
        for (int i = 0; i < N; i++)
            par[i] = i;
    }
    int root(int x) {  // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }
    void unite(int x, int y) {  // xとyの木を併合
        int rx = root(x);       //xの根をrx
        int ry = root(y);       //yの根をry
        if (rx == ry)
            return;    //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry;  //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }
    bool same(int x, int y) {  // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        uf.unite(x, y);
    }
    set<int> ans;
    for (int i = 0; i < n; i++) {
        ans.insert(uf.root(i));
    }
    cout << ans.size() << endl;
}