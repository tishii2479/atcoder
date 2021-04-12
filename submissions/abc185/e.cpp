#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
#define each(i, mp) for (auto &i : mp)
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
const ll INF = 1LL << 60;
const int inf = 1 << 29;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, inf));
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i > 0)
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);
            if (j > 0)
                dp[i][j] = min(dp[i][j - 1] + 1, dp[i][j]);
            if (j > 0 and i > 0) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i][j]);
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i][j]);
                }
            }
        }
    }
    cout << dp[n][m] << endl;
}