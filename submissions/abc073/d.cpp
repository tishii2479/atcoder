#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n, m, R;
    cin >> n >> m >> R;
    vector<int> r(R);
    for (int i = 0; i < R; i++) {
        cin >> r[i];
        r[i]--;
    }
    vector<vector<ll>> cost(n, vector<ll>(n, INF));
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--, b--;
        cost[a][b] = cost[b][a] = c;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
    ll ans = INF;
    vector<vector<ll>> dp(1 << R, vector<ll>(R, INF));
    for (int i = 0; i < R; i++)
        dp[1 << i][i] = 0;
    for (int bits = 0; bits < (1 << R); bits++)
        for (int now = 0; now < R; now++)
            if (bits & (1 << now))
                for (int nxt = 0; nxt < R; nxt++)
                    if ((bits & (1 << nxt)) == false) {
                        dp[bits | (1 << nxt)][nxt] = min(dp[bits | (1 << nxt)][nxt], dp[bits][now] + cost[r[now]][r[nxt]]);
                    }
    for (int i = 0; i < R; i++) {
        ans = min(ans, dp[(1 << R) - 1][i]);
    }
    cout << ans << endl;
}