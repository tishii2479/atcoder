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
    using mint = modint1000000007;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // dp[i][j] := i人目まででj個飴を使った時の方法の通り
    // init -> dp[0][0] = 1
    // answer := dp[n][k]
    vector<vector<mint>> dp(n + 1, vector<mint>(k + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        vector<mint> sum(k + 2, 0);
        for (int j = 0; j <= k; j++)
            sum[j + 1] += sum[j] + dp[i][j];
        for (int j = 0; j <= k; j++)
            dp[i + 1][j] = sum[j + 1] - sum[max(0, j - a[i])];
    }
    cout << dp[n][k].val() << endl;
}