#include <bits/stdc++.h>
using namespace std;
double calc(int v1, int v2, int mxv, int t) {
    double all;
    if (mxv - v1 + mxv - v2 <= t) {
        all = mxv * t;
        all -= (double)(mxv - v2) * (mxv - v2) / 2;
        all -= (double)(mxv - v1) * (mxv - v1) / 2;
    } else {
        if (v1 < v2)
            swap(v1, v2);
        all = v1 * t;
        double t2 = v1 - v2;
        double t1 = t - t2;
        all += t1 * t1 / 4;
        all -= t2 * t2 / 2;
    }
    return all;
}
int main() {
    int n;
    cin >> n;
    vector<int> t(n), v(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    const double INF = (1e15);
    // dp[i][j] := i番目が終わった時に、速度がjである時の最大の距離
    vector<vector<double>> dp(n + 1, vector<double>(110, -INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 110; j++) {
            if (j > v[i] or j > v[i + 1]) {
                dp[i + 1][j] = -INF;
                continue;
            }
            for (int k = 0; k < 110; k++) {
                if (abs(j - k) > t[i])
                    continue;
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][k] + calc(k, j, v[i], t[i]));
            }
        }
    }
    cout << fixed << setprecision(10) << dp[n][0] << endl;
}