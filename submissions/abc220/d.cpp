#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;

int main() {
    using mint = atcoder::modint998244353;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<mint>> dp(n, vector<mint>(10, 0));
    dp[0][a[0]] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            // a+b
            dp[i][(j + a[i]) % 10] += dp[i - 1][j];
            // a*b
            dp[i][(j * a[i]) % 10] += dp[i - 1][j];
        }
    }

    for (int i = 0; i < 10; i++) {
        cout << dp[n - 1][i].val() << endl;
    }
}
