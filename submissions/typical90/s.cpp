#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    const ll inf = 1 << 28;
    ll n;
    cin >> n;
    n *= 2;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    ll dp[410][410];
    for (ll i = 0; i < 410; i++)
        for (ll j = 0; j < 410; j++) dp[i][j] = inf;
    for (ll wid = 0; wid <= n; wid += 2) {
        for (ll l = 0; l < n; l++) {
            if (wid == 0) {
                dp[l][l] = 0;
                continue;
            }
            ll r = l + wid;
            if (r > n) continue;
            for (ll k = l + 1; k <= r; k += 2) {
                dp[l][r] = min(dp[l][r], dp[l + 1][k] + abs(a[l] - a[k]) + dp[k + 1][r]);
            }
            for (ll k = r - 1; k >= l; k -= 2) {
                dp[l][r] = min(dp[l][r], dp[k][r - 1] + abs(a[r - 1] - a[k - 1]) + dp[l][k - 1]);
            }
        }
    }

    cout << dp[0][n] << endl;
}
