#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
using Graph = vector<vector<pint>>;
Graph G;
int n, m;
void rec(int v, int c, vector<int> &res) {
    res[v] = c;
    for (auto e : G[v]) {
        if (res[e.first] != -1)
            continue;
        if (e.second == c)
            rec(e.first, (e.second + 1) % n, res);
        else
            rec(e.first, e.second, res);
    }
}
int main() {
    cin >> n >> m;
    G.assign(n, vector<pint>());
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        c--;
        G[u].push_back({v, c});
        G[v].push_back({u, c});
    }
    vector<int> res(n, -1);
    rec(0, 0, res);
    for (auto v : res) {
        cout << v + 1 << endl;
    }
}