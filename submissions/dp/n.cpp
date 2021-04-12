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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, INF));
    vector<ll> sum(n + 1, 0);
    for (int i = 0; i < n; i++)
        sum[i + 1] = sum[i] + a[i];
    for (int i = 0; i < n; i++)
        dp[i][i] = dp[i][i + 1] = 0;
    dp[n][n] = 0;
    for (int wid = 1; wid <= n; wid++)
        for (int l = 0; l + wid <= n; l++) {
            int r = l + wid;
            for (int k = l + 1; k < r; k++)
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r] + sum[r] - sum[l]);
        }
    cout << dp[0][n] << endl;
}