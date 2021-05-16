#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

using mint = modint1000000007;
using ll = long long;
const int N = 210000;
vector<vector<pair<int, ll>>> edges(N);
int dp[N][61];

void dfs(int cur = 0, int par = -1) {
    for (auto p : edges[cur]) {
        int u = p.first;
        ll w = p.second;
        if (u == par) continue;
        for (int i = 0; i < 61; i++) {
            if (w & (1LL << i)) {
                dp[u][i] = 1 - dp[cur][i];
            } else {
                dp[u][i] = dp[cur][i];
            }
        }
        dfs(u, cur);
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--, v--;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    dfs();

    mint ans = 0;

    for (int i = 0; i < 61; i++) {
        mint cnt = 0;
        for (int v = 0; v < n; v++)
            if (dp[v][i] == 0) cnt++;
        // cout << i << " " << cnt.val() << endl;
        ans += cnt * (n - cnt) * mint(1LL << i);
    }

    cout << ans.val() << endl;
}
