#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
int main() {
    using mint = modint1000000007;
    string s;
    cin >> s;
    int n = s.length();
    mint dp[n + 1][2];
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            dp[i + 1][0] = dp[i][0] * 2;
            dp[i + 1][1] = dp[i][0] + dp[i][1] * 3;
        } else {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = dp[i][1] * 3;
        }
    }
    cout << (dp[n][0] + dp[n][1]).val() << endl;
}