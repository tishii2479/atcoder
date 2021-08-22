#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;

vector<int> dp;
vector<vector<int>> edges;

using mint = atcoder::modint1000000007;
mint ans = 0;
int n;

void dfs(int v = 0, int par = -1) {
    dp[v] = 1;
    ans += mint(2).pow(n - 1);

    for (int u : edges[v]) {
        if (u == par) continue;
        dfs(u, v);
        dp[v] += dp[u];
        ans -= mint(2).pow(dp[u]);
    }
    if (n - dp[v] >= 1)
        ans -= mint(2).pow(n - dp[v]);

    ans += edges[v].size() - 1;
}

int main() {
    cin >> n;
    dp.resize(n), edges.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs();

    cout << (ans / mint(2).pow(n)).val() << endl;
}
