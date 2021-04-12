#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
const int N = 110000;
vector<mint> dp_white(N, 1);
vector<mint> dp_black(N, 1);
vector<vector<int>> edges(N);
void dfs(int v, int par) {
    for (int u : edges[v]) {
        if (u == par) continue;
        dfs(u, v);
        dp_black[v] *= dp_white[u];
        dp_white[v] *= (dp_white[u] + dp_black[u]);
    }
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(0, -1);
    cout << (dp_white[0] + dp_black[0]).val() << endl;
}