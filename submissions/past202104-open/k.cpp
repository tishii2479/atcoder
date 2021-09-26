#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    const long long inf = 1LL << 60;
    vector<vector<long long>> dp(n + 1, vector<long long>(100, -inf));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        long long p, u;
        cin >> p >> u;
        for (int j = 0; j < 100; j++) {
            dp[i + 1][j] = dp[i][j];
        }
        for (int j = 0; j < 100; j++) {
            int nxt = (j + p) % 100;
            int cnt = (j + p) / 100;
            dp[i + 1][nxt] = max(dp[i + 1][nxt], dp[i][j] + u + cnt * 20 - p);
        }
    }

    long long ans = -inf;
    for (int i = 0; i < 100; i++) ans = max(ans, dp[n][i]);
    cout << ans << endl;
}
