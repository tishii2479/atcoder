#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
pint dp[210][2];
int main() {
    int d, n;
    cin >> d >> n;
    vector<int> t(d);
    for (int i = 0; i < d; i++)
        cin >> t[i];
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i];
    dp[0][0] = dp[0][1] = {0, 0};
    for (int i = 0; i < d; i++) {
        int mn = 101, mx = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] <= t[i] and t[i] <= b[j]) {
                mn = min(mn, c[j]);
                mx = max(mx, c[j]);
            }
        }
        if (i == 0) {
            dp[i + 1][0] = {0, mn};
            dp[i + 1][1] = {0, mx};
        } else {
            dp[i + 1][0] = {max(abs(dp[i][0].second - mn) + dp[i][0].first, abs(dp[i][1].second - mn) + dp[i][1].first), mn};
            dp[i + 1][1] = {max(abs(dp[i][0].second - mx) + dp[i][0].first, abs(dp[i][1].second - mx) + dp[i][1].first), mx};
        }
    }
    // for (int i = 0; i <= d; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //         cout << dp[i][j].first << " " << dp[i][j].second << " ";
    //     cout << endl;
    // }
    cout << max(dp[d][0].first, dp[d][1].first) << endl;
}