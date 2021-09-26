#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;

int main() {
    using mint = atcoder::modint998244353;
    int n, m;
    cin >> n >> m;
    vector<vector<mint>> dp(n + 1, vector<mint>(n + 1, 0));

    dp[0][0] = 1;

    // dp[people][group]
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] * max(0, (j - (i - 1) / m));
        }
    }

    for (int i = 1; i <= n; i++) cout << dp[n][i].val() << endl;
}
