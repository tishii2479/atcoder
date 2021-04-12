#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
// const int MOD = 1000000007;
const int MOD = 998244353;
int main() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(s + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= s; j++) {
            dp[i + 1][j] += dp[i][j] * 2;
            if (j - a[i] >= 0)
                dp[i + 1][j] += dp[i][j - a[i]];
            dp[i + 1][j] %= MOD;
        }
    }
    cout << dp[n][s] << endl;
}