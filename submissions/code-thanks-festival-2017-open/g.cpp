#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> edges(n, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a][b] = edges[b][a] = true;
    }
    vector<bool> ok(1 << (n / 2), true);
    for (int i = 0; i < n / 2; i++)
        for (int j = 0; j < n / 2; j++)
            if (edges[i][j])
                ok[(1 << i) | (1 << j)] = false;
    for (int s = 0; s < 1 << (n / 2); s++)
        for (int w = 0; w < n / 2; w++)
            if ((s & (1 << w)) == false and ok[s] == false)
                ok[s | (1 << w)] = false;
    vector<int> with(1 << (n / 2), 0);
    with[0] = (1 << (n - n / 2)) - 1;
    for (int i = 0; i < n / 2; i++)
        for (int j = n / 2; j < n; j++)
            if (edges[i][j] == false)
                with[1 << i] |= (1 << (j - n / 2));
    for (int s = 0; s < 1 << (n / 2); s++)
        for (int w = 0; w < n / 2; w++)
            if ((s & (1 << w)) == false)
                with[s | (1 << w)] = with[s] & with[1 << w];
    vector<bool> ok2(1 << (n - n / 2), true);
    for (int i = n / 2; i < n; i++)
        for (int j = n / 2; j < n; j++)
            if (edges[i][j])
                ok2[(1 << (i - n / 2)) | (1 << (j - n / 2))] = false;
    for (int s = 0; s < 1 << (n - n / 2); s++)
        for (int w = n / 2; w < n; w++)
            if ((s & (1 << (w - n / 2))) == false and ok2[s] == false)
                ok2[s | (1 << (w - n / 2))] = false;
    vector<int> dp(1 << (n - n / 2), 0);
    for (int s = 0; s < 1 << (n - n / 2); s++)
        dp[s] = (ok2[s] ? __builtin_popcount(s) : 0);
    for (int s = 0; s < 1 << (n - n / 2); s++)
        for (int w = n / 2; w < n; w++)
            if ((s & (1 << (w - n / 2))) == false)
                dp[s | (1 << (w - n / 2))] = max(dp[s | (1 << (w - n / 2))], dp[s]);
    int ans = 0;
    for (int s = 0; s < 1 << (n / 2); s++)
        if (ok[s])
            ans = max(ans, __builtin_popcount(s) + dp[with[s]]);
    cout << ans << endl;
}