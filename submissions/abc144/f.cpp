#include <bits/stdc++.h>
using namespace std;

const int N = 610;

vector<int> topo;
vector<int> seen(N);
vector<vector<int>> edges(N);
vector<double> dp(N, 0);
vector<double> effect(N, 0);

void dfs(int v = 0) {
    seen[v] = true;
    for (int u : edges[v]) {
        if (seen[u]) continue;
        dfs(u);
    }
    topo.push_back(v);
}

double solve(int s = -1, int t = -1) {
    for (int v : topo) {
        int cnt = 0;
        double val = 0;

        for (int u : edges[v]) {
            if (s == v and t == u) continue;
            val += dp[u];
            cnt++;
        }
        if (cnt == 0) {
            dp[v] = 0;
        } else {
            dp[v] = val / cnt + 1;
        }
    }

    return dp[0];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> path(m);

    for (int i = 0; i < m; i++) {
        int s, t;
        cin >> s >> t;
        s--, t--;
        edges[s].push_back(t);
        path[i] = {s, t};
    }

    dfs();

    effect[0] = 1;

    for (int i = topo.size() - 1; i >= 0; i--) {
        int v = topo[i];
        for (int u : edges[v]) {
            effect[u] += effect[v] / edges[v].size();
        }
    }

    double ans = solve();
    double all = ans;

    // for (auto e : effect) cout << e << " ";
    // cout << endl;

    vector<double> sums(N, 0);
    for (int i = 0; i < n; i++) {
        for (int u : edges[i]) sums[i] += dp[u];
    }

    for (int i = 0; i < m; i++) {
        int s = path[i].first, t = path[i].second;
        int sz = edges[s].size();
        if (sz == 1) continue;

        double sum = sums[s];
        double sum2 = sum - dp[t];
        double val = all + effect[s] * ((sum2 / (sz - 1) - sum / sz));

        ans = min(ans, val);
    }

    cout << fixed << setprecision(10) << ans << endl;
}
