#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

int main() {
    using mint = modint1000000007;
    int n;
    string s;
    string t = "atcoder";
    cin >> n >> s;
    vector<vector<mint>> dp(n + 1, vector<mint>(8));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 8; j++) {
            dp[i + 1][j] = dp[i][j];
        }
        for (int j = 0; j < 7; j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] += dp[i][j];
            }
        }
    }

    cout << dp[n][7].val() << endl;
}
