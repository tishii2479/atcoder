#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;

int main() {
    using mint = atcoder::modint1000000007;
    int n;
    string s;
    cin >> n >> s;

    vector<vector<mint>> dp(n, vector<mint>(n, 0));
    for (int i = 0; i < n; i++) dp[0][i] = 1;

    for (int i = 0; i < n - 1; i++) {
        // 0 = decrease, 1 = increase
        const int cur = (s[i] == '<');
        mint sum = 0;
        if (cur == 1) {
            for (int j = 0; j < n - i; j++) {
                sum += dp[i][j];
                dp[i + 1][j] += sum;
            }
        } else {
            for (int j = n - i - 1; j >= 0; j--) {
                dp[i + 1][j] += sum;
                sum += dp[i][j];
            }
        }
    }

    cout << dp[n - 1][0].val() << endl;
}
