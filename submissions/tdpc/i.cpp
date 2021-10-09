#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    const int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int w = 1; w <= n; w++) {
        for (int l = 0; l + w <= n; l++) {
            int r = l + w;

            for (int k = l + 1; k < r; k++) {
                dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r]);
                if (w % 3 != 0) continue;
                if (!(s[l] == 'i' and s[r - 1] == 'i' and s[k] == 'w')) continue;
                if (!(dp[l + 1][k] * 3 == k - (l + 1) and dp[k + 1][r - 1] * 3 == (r - 1) - (k + 1))) continue;
                dp[l][r] = max(dp[l][r], w / 3);
            }
        }
    }
    cout << dp[0][n] << endl;
}
