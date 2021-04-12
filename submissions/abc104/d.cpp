#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = (int)1e9 + 7;
// const int MOD = 998244353;
int main() {
    using mint = modint1000000007;
    string s;
    cin >> s;
    int n = s.length();
    // 0 = with ? ?
    // 1 = with ? B or A ?
    // 2 = with A B
    vector<vector<mint>> dp(n + 1, vector<mint>(3, 0));
    int acnt = 0;
    int bcnt = 0;
    int q = 0;
    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[i];
        if (s[i] == 'A') {
            acnt++;
        } else if (s[i] == 'B') {
            dp[i + 1][1] += q;
            dp[i + 1][2] += acnt;
            bcnt++;
        } else if (s[i] == '?') {
            // s[i] == '?'
            dp[i + 1][1] += acnt;
            dp[i + 1][0] += q;
            q++;
        }
    }
    mint ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'C') {
            for (int j = 0; j < 3; j++)
                if (q + j - 2 >= 0)
                    ans += dp[i][j] * pow_mod(3, q + j - 2, MOD);
        } else if (s[i] == '?') {
            for (int j = 0; j < 3; j++)
                if (q + j - 3 >= 0)
                    ans += dp[i][j] * pow_mod(3, q + j - 3, MOD);
        }
    }
    cout << ans.val() << endl;
}