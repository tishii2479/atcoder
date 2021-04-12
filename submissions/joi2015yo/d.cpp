#include <bits/stdc++.h>
using namespace std;
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
    vector<int> d(n), c(m);
    for (int i = 0; i < n; i++)
        cin >> d[i];
    for (int i = 0; i < m; i++)
        cin >> c[i];
    // dp[used_days][city]
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, inf));
    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;
    // i日目までに都市jに到達している時の、最小の疲労度
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            // min(dp[i + 1][j], min(dp[i][j]) + d[i] * min(c[j]))
            dp[i + 1][j + 1] = dp[i][j + 1];
            for (int k = 0; k <= i; k++) {
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[k][j] + d[j] * c[k]);
            }
        }
    // for (int i = 0; i <= m; i++)
    // {
    //     for (int j = 0; j <= n; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    cout << dp[m][n] << endl;
}