#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    int n, k;
    cin >> n >> k;
    vector<ll> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    h.insert(h.begin(), 0);

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 1LL << 60));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n - k; j++) {
            for (int r = 0; r < i; r++) {
                if (j == 0) continue;
                dp[i][j] = min(dp[i][j], dp[r][j - 1] + max(0LL, h[i] - h[r]));
            }
        }
    }

    ll ans = 1LL << 60;

    for (int i = 0; i <= n; i++) ans = min(ans, dp[i][n - k]);

    cout << ans << endl;
}
