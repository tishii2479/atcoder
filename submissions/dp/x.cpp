#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> idx(n);
    for (long long i = 0; i < n; i++) idx[i] = i;
    vector<long long> w(n), s(n), v(n);
    for (long long i = 0; i < n; i++) cin >> w[i] >> s[i] >> v[i];

    sort(idx.begin(), idx.end(), [&](long long i, long long j) {
        return s[i] + w[i] < s[j] + w[j];
    });

    const long long N = 21000;
    const long long inf = 1LL << 60;
    // dp[i][weight];
    vector<vector<long long>> dp(n + 1, vector<long long>(N, -inf));
    dp[0][0] = 0;

    long long cur = 0;
    for (long long i : idx) {
        for (long long j = N - 1; j >= 0; j--) {
            dp[cur + 1][j] = dp[cur][j];
            if (j - w[i] < 0) continue;
            if (j - w[i] > s[i]) continue;
            dp[cur + 1][j] = max(dp[cur + 1][j], dp[cur][j - w[i]] + v[i]);
        }
        cur++;
    }

    long long ans = -inf;
    for (long long i = 0; i < N; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
}
