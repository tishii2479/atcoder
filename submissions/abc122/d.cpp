#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
// 0 = A, 1 = C, 2 = G, 3 = T, 4 = x
// invalid pattern
// 02 -> 1
// 01 -> 2
// 20 -> 1
// 02x -> 1
// 0x2 -> 1
// n, prevprev, prev, now
ll dp[110][5][5][5];
int main() {
    ll n;
    cin >> n;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++) {
                if ((i == 0 and j == 2 and k == 1) or
                    (i == 0 and j == 1 and k == 2) or
                    (i == 2 and j == 0 and k == 1))
                    dp[3][i][j][k] = 0;
                else
                    dp[3][i][j][k] = 1;
            }
    for (int i = 3; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 4; l++) {
                    for (int m = 0; m < 4; m++) {
                        if ((k == 0 and l == 2 and m == 1) or
                            (k == 0 and l == 1 and m == 2) or
                            (k == 2 and l == 0 and m == 1) or
                            (j == 0 and k == 2 and m == 1) or
                            (j == 0 and l == 2 and m == 1))
                            continue;
                        dp[i + 1][k][l][m] += dp[i][j][k][l];
                        dp[i + 1][k][l][m] %= MOD;
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++) {
                ans += dp[n][i][j][k];
                ans %= MOD;
            }
    cout << ans << endl;
}