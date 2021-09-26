#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    int n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];

    // dp[s] :=
    vector<ll> dp(1 << n, 0);

    for (int bit = 0; bit < (1 << n); bit++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (bit & (1 << i) and bit & (1 << j)) dp[bit] += a[i][j];
            }
        }

        for (int bit2 = bit; bit2 >= 0; bit2--) {
            bit2 &= bit;
            if (bit2 == bit or bit2 == 0) continue;
            dp[bit] = max(dp[bit], dp[bit2] + dp[bit ^ bit2]);
        }
    }

    cout << dp[(1 << n) - 1] << endl;
}
