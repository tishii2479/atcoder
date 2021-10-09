#include <bits/stdc++.h>
using namespace std;

const int N = 210000;
using ll = long long;
using P = pair<ll, ll>;
const ll INF = 1LL << 60;
vector<vector<P>> edges(N);
vector<ll> d(N);
vector<ll> dp(N, -INF);
vector<ll> ans(N, -INF);

void dfs(int cur, int par, ll dist) {
    for (auto [u, c] : edges[cur]) {
        if (par == u) continue;
        dfs(u, cur, dist + c);
        dp[cur] = max(dp[cur], dp[u] + c);
        // using u
        dp[cur] = max(dp[cur], d[u] + c);
    }
}

void dfs2(int cur, int par, ll par_max) {
    // cout << cur << " " << par << " " << par_max << endl;
    ans[cur] = max(dp[cur], par_max);

    const int n = edges[cur].size();
    vector<ll> left_max(n + 1, -INF), right_max(n + 1, -INF);
    for (int i = 0; i < n; i++) {
        auto [u, c] = edges[cur][i];
        if (u == par) {
            left_max[i + 1] = left_max[i];
            continue;
        }

        left_max[i + 1] = max({left_max[i], dp[u] + c, d[u] + c});
    }

    for (int i = n - 1; i >= 0; i--) {
        auto [u, c] = edges[cur][i];
        if (u == par) {
            right_max[i] = right_max[i + 1];
            continue;
        }
        right_max[i] = max({right_max[i + 1], dp[u] + c, d[u] + c});
    }

    for (int i = 0; i < n; i++) {
        auto [u, c] = edges[cur][i];
        if (u == par) continue;
        // cout << cur << " " << left_max[i] << " " << right_max[i + 1] << " " << d[cur] << endl;
        dfs2(u, cur, max({left_max[i], right_max[i + 1], d[cur], par_max}) + c);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    for (int i = 0; i < n; i++) cin >> d[i];

    dfs(0, -1, 0);
    // for (int i = 0; i < n; i++) cout << dp[i] << " ";
    // cout << endl;
    dfs2(0, -1, -INF);

    for (int i = 0; i < n; i++) cout << ans[i] << endl;
}
