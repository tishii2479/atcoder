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
    vector<int> s(n);
    vector<int> t(m);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int j = 0; j < m; j++)
        cin >> t[j];
    vector<vector<ll>> dp(2100, vector<ll>(2100, 0));
    vector<vector<ll>> sdp(2100, vector<ll>(2100, 0));
    dp[0][0] = 1;
    sdp[1][1] = 1;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++) {
            if (i == 0 and j == 0)
                continue;
            if (i - 1 >= 0 and j - 1 >= 0 and s[i - 1] == t[j - 1])
                dp[i][j] = sdp[i][j] % MOD;
            sdp[i + 1][j + 1] = sdp[i][j + 1] + sdp[i + 1][j] - sdp[i][j] + dp[i][j];
            sdp[i + 1][j + 1] %= MOD;
        }
    cout << (sdp[n + 1][m + 1] + MOD) % MOD << endl;
}
// dp[i][j] :=
// sをi番目、tをj番目までみたときの部分列の組
//