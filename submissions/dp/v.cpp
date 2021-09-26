#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;

const int N = 110000;
vector<vector<int>> edges(N);
vector<atcoder::modint> dp(N);
vector<atcoder::modint> ans(N);

void dfs(int cur = 0, int par = -1) {
    dp[cur] = 1;
    for (int u : edges[cur]) {
        if (u == par) continue;
        dfs(u, cur);
        dp[cur] *= (dp[u] + 1);
    }
}

void dfs2(int cur = 0, int par = -1, atcoder::modint par_val = 1) {
    const int n = edges[cur].size();
    vector<atcoder::modint> left(n + 1, 1), right(n + 1, 1);
    ans[cur] = dp[cur] * par_val;

    for (int i = 0; i < n; i++) {
        int u = edges[cur][i];
        left[i + 1] = left[i] * (u == par ? 1 : (dp[u] + 1));
    }

    for (int i = n - 1; i >= 0; i--) {
        int u = edges[cur][i];
        right[i] = right[i + 1] * (u == par ? 1 : (dp[u] + 1));
    }

    for (int i = 0; i < n; i++) {
        int u = edges[cur][i];
        if (u == par) continue;
        dfs2(u, cur, par_val * left[i] * right[i + 1] + 1);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    atcoder::modint::set_mod(m);

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    dfs();
    dfs2();

    for (int i = 0; i < n; i++)
        cout << ans[i].val() << endl;
}
