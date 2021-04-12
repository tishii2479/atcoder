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
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll ans = INF;
    for (int m = 1; m <= n; m++) {
        vector<vector<vector<ll>>> dp(110, vector<vector<ll>>(110, vector<ll>(110, -INF)));
        for (int i = 0; i <= n; i++)
            dp[0][i][0] = 0;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    dp[i + 1][j + 1][k] = max(dp[i + 1][j][k], dp[i][j][(((k - a[j]) % m) + m) % m] + a[j]);
                    // cout << i << " " << j << " " << k << " " << dp[i + 1][j][k] << " " << dp[i][j][(((k - a[j]) % m) + m) % m] + a[j] << " " << (((k - a[j]) % m) + m) % m << endl;
                }
            }
        }
        // dp[m][n][x % m] / m
        // for (int i = 0; i <= m; i++)
        // {
        //     for (int j = 0; j <= n; j++)
        //     {
        //         for (int k = 0; k < m; k++)
        //             cout << (dp[i][j][k] < 0 ? "-1" : to_string(dp[i][j][k])) << ":";
        //         cout << " ";
        //     }
        //     cout << endl;
        // }
        // cout << dp[m][n][x % m] << endl;
        if (dp[m][n][x % m] < 0)
            continue;
        ans = min(ans, (x - dp[m][n][x % m]) / m);
    }
    cout << ans << endl;
}