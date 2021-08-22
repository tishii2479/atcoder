#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    int n;
    cin >> n;
    vector<pair<ll, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -(1LL << 60)));
    dp[0][0] = 0;

    sort(a.begin(), a.end(), greater<pair<ll, int>>());

    for (int i = 0; i < n; i++) {
        int did = i + 1;
        for (int j = 0; j <= did; j++) {
            int k = did - j;
            if (j > 0) {
                dp[j][k] = max(dp[j - 1][k] + abs(a[i].second - (j - 1)) * a[i].first, dp[j][k]);
            }
            if (k > 0) {
                dp[j][k] = max(dp[j][k - 1] + abs((n - k) - a[i].second) * a[i].first, dp[j][k]);
            }
        }
    }

    ll ans = -(1LL << 60);

    for (int i = 0; i <= n; i++) {
        ans = max(ans, dp[i][n - i]);
    }
    cout << ans << endl;
}
