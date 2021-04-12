#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
ll dp[51][51][2551];
int main() {
    int n, a;
    cin >> n >> a;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < 2501; k++) {
                dp[i + 1][j][k] += dp[i][j][k];
                if (j > 0 and k - x[i] >= 0) {
                    dp[i + 1][j][k] += dp[i][j - 1][k - x[i]];
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[n][i][i * a];
    }
    cout << ans << endl;
}