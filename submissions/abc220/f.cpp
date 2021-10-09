#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 210000;
using ll = long long;
vector<vector<int>> edges(N);
vector<ll> ans(N, 0);
vector<int> sz(N, 0);
vector<ll> dp(N, 0);

void dfs(int cur = 0, int par = -1) {
    sz[cur] = 1;
    dp[cur] = 0;
    for (int u : edges[cur]) {
        if (u == par) continue;
        dfs(u, cur);
        sz[cur] += sz[u];
        dp[cur] += dp[u] + sz[u];
    }
}

void dfs2(int cur = 0, int par = -1, ll par_v = 0) {
    ans[cur] = dp[cur] + par_v;
    ll sum_dp = 0, sum_sz = n - 1;
    for (int u : edges[cur]) {
        if (u == par) continue;
        sum_dp += dp[u] + sz[u];
    }
    for (int u : edges[cur]) {
        if (u == par) continue;
        dfs2(u, cur, par_v + (sum_sz - sz[u]) + sum_dp - (dp[u] + sz[u]) + 1);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs();
    dfs2();

    for (int i = 0; i < n; i++) cout << ans[i] << endl;
}
