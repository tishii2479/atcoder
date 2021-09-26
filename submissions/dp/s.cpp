#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;

using mint = atcoder::modint1000000007;
mint dp[110000][110][2];

int main() {
    string s;
    int d;
    cin >> s >> d;

    const int n = s.length();

    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        const int v = s[i] - '0';
        for (int j = 0; j < d; j++) {
            for (int k = 0; k < v; k++) {
                // equal to smaller
                dp[i + 1][(j + k) % d][1] += dp[i][j][0];
            }
            // equal
            dp[i + 1][(j + v) % d][0] += dp[i][j][0];

            // smaller to smaller
            for (int k = 0; k < 10; k++) {
                dp[i + 1][(j + k) % d][1] += dp[i][j][1];
            }
        }
    }

    cout << (dp[n][0][0] + dp[n][0][1] - 1).val() << endl;
}
