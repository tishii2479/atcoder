#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
int main() {
    using mint = modint998244353;
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    const int S = s * 2 + 100;
    // dp[i][j] := 0からi番目を使って、合計がjの場合の数
    vector<vector<mint>> dp(n + 1, vector<mint>(S, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < S; j++) {
            dp[i + 1][j] += dp[i][j];
            if (j + a[i] < S)
                dp[i + 1][j + a[i]] += dp[i][j];
        }
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= s; j++)
    //         cout << dp[i][j].val() << " ";
    //     cout << endl;
    // }
    mint ans = 0;
    for (int i = 0; i <= n; i++)
        ans += dp[i][s];
    cout << ans.val() << endl;
}