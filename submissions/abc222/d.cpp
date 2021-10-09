#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;

int main() {
    using mint = atcoder::modint998244353;
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    const int N = 3100;
    vector<vector<mint>> dp(N, vector<mint>(N, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        mint sum = 0;
        for (int j = 0; j < N; j++) {
            sum += dp[i][j];
            if (a[i] <= j and j <= b[i]) {
                dp[i + 1][j] = sum;
            }
        }
    }

    mint ans = 0;
    for (int i = 0; i < N; i++) ans += dp[n][i];
    cout << ans.val() << endl;
}
