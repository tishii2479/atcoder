#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int w = 1; w <= n; w++) {
        for (int l = 0; l + w < n; l++) {
            int r = l + w;
            dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);

            for (int m = l; m < r; m++) dp[l][r] = max(dp[l][r], dp[l][m] + dp[m + 1][r]);

            if (s[l] != t[0] or s[r] != t[2]) continue;

            for (int m = l + 1; m < r; m++) {
                if (s[m] != t[1]) continue;
                if (dp[l + 1][m - 1] * 3 == m - l - 1 and r - m - 1 == dp[m + 1][r - 1] * 3) {
                    assert((r - l + 1) % 3 == 0);
                    dp[l][r] = (r - l + 1) / 3;
                }
            }
        }
    }

    cout << dp[0][n - 1] << endl;
}
