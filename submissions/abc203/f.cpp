#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    const int N = 31, inf = 1 << 30;
    // dp[idx][val] := aoki_min_cnt
    vector<vector<int>> dp(n + 1, vector<int>(N, inf));
    for (int i = 0; i < N; i++) dp[0][i] = 0;

    vector<int> idx(n);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        while (a[cur] <= a[i] / 2) cur++;
        idx[i] = cur;
    }

    for (int i = 0; i < n; i++) {
        dp[i + 1][0] = dp[i][0] + 1;
        for (int j = 0; j + 1 < N; j++) {
            dp[i + 1][j + 1] = min(dp[i][j + 1] + 1, dp[idx[i]][j]);
        }
    }

    for (int i = 0; i <= N; i++) {
        if (dp[n][i] <= k) {
            cout << i << " " << dp[n][i] << endl;
            return 0;
        }
    }
}
