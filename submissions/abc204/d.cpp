#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> t(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        sum += t[i];
    }

    const int N = 1000 * 110;
    vector<vector<bool>> dp(n + 1, vector<bool>(N, 0));
    dp[0][0] = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < N; j++) {
            if (dp[i][j] == false) continue;
            if (j + t[i] >= N) continue;
            dp[i + 1][j] = true;
            dp[i + 1][j + t[i]] = true;
        }
    }

    int ans = 1 << 30;
    for (int i = 0; i < N; i++) {
        if (dp[n][i]) ans = min(ans, max(i, sum - i));
    }
    cout << ans << endl;
}
