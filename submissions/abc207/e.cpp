#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

using mint = modint1000000007;
mint dp[3100][3100];

int main() {
    using ll = long long;
    const ll N = 3100;
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> sums(n + 1, 0);
    for (int i = 0; i < n; i++) sums[i + 1] = sums[i] + a[i];

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) dp[i + 1][1] = 1;

    for (int i = 2; i < N; i++) {
        vector<mint> cnt(i, 0);
        for (int j = 1; j <= n; j++) {
            dp[j][i] += cnt[sums[j] % i];
            cnt[sums[j] % i] += dp[j][i - 1];
        }
    }

    mint ans = 0;
    for (int i = 0; i < N; i++) {
        ans += dp[n][i];
        // cout << dp[n][i].val() << endl;
    }

    cout << ans.val() << endl;
}
