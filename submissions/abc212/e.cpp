#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

int main() {
    using mint = atcoder::modint998244353;
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> edges(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (int i = 0; i < n; i++) edges[i].push_back(i);

    vector<vector<mint>> dp(k + 1, vector<mint>(n, 0));
    dp[0][0] = 1;

    for (int i = 0; i < k; i++) {
        mint sum = 0;
        for (int j = 0; j < n; j++) sum += dp[i][j];

        for (int j = 0; j < n; j++) {
            dp[i + 1][j] = sum;
            for (int u : edges[j]) dp[i + 1][j] -= dp[i][u];
        }
    }

    cout << dp[k][0].val() << endl;
}
