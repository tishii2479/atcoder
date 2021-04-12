#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
ll dp[1100000][2];
int main() {
    ll n, k;
    cin >> n >> k;
    dp[0][0] = 1;
    dp[0][0] = 1;
    dp[1][0] = 0;
    dp[1][1] = 1;
    for (ll i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
        if (i - k >= 0)
            dp[i][1] -= dp[i - k][0];
        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
        // cout << i << " " << dp[i][0] << " " << dp[i][1] << endl;
    }
    cout << (dp[n][1] + MOD) % MOD << endl;
}