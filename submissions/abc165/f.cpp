#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
vector<ll> dp(200000 + 10, inf);
vector<bool> seen(200000, false);
vector<int> res(200000, 0);
vector<ll> a(200000);
vector<int> edges[210000];
int n;
void dfs(int v) {
    ll tmp;
    auto it = lower_bound(dp.begin(), dp.end(), a[v]);
    tmp = *it;
    *it = a[v];
    res[v] = lower_bound(dp.begin(), dp.end(), inf) - dp.begin();
    // cout << v << ": ";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << (dp[i] == inf ? "inf" : to_string(dp[i])) << " ";
    // }
    // cout << endl;
    for (int u : edges[v]) {
        if (seen[u])
            continue;
        seen[u] = true;
        dfs(u);
    }
    *it = tmp;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    seen[0] = true;
    dfs(0);
    for (int i = 0; i < n; i++) {
        cout << res[i] << endl;
    }
}