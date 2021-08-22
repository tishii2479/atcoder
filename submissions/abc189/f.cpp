#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> w(k);
    for (int i = 0; i < k; i++) cin >> w[i];

    vector<bool> isWarp(n + 1, false);
    for (int i = 0; i < k; i++) isWarp[w[i]] = true;

    int last = -1;
    for (int i = 0; i < n; i++) {
        if (isWarp[i] == false)
            last = -1;
        else {
            if (last == -1) last = i;
            if (i - last + 1 >= m) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    long double l = 0, r = 1LL << 60;
    for (int _ = 0; _ < 2000; _++) {
        long double e = (r + l) / 2;

        vector<long double> dp(n + 1, 0);
        long double sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (isWarp[i])
                dp[i] = e;
            else
                dp[i] = sum / m + 1;

            sum += dp[i];
            sum -= dp[min(n, i + m)];
        }

        if (e < dp[0]) {
            l = e;
        } else {
            r = e;
        }
    }

    cout << fixed << setprecision(10) << l << endl;
}
