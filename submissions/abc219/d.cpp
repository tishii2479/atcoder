#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    const int inf = 1 << 30;

    vector<vector<int>> dp(x + 1, vector<int>(y + 1, inf));
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= 0; j--) {
            for (int k = y; k >= 0; k--) {
                dp[min(x, j + a[i])][min(y, k + b[i])] = min(dp[min(x, j + a[i])][min(y, k + b[i])], dp[j][k] + 1);
            }
        }
    }

    if (dp[x][y] == inf) {
        cout << -1 << endl;
    } else {
        cout << dp[x][y] << endl;
    }
}
