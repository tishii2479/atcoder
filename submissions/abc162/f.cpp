#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 50;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
// idx, skip_cnt, used
ll dp[210000][3][2];
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dp[0][1][0] = dp[0][1][1] = dp[0][2][0] = dp[0][2][1] = -INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i + 1][j][0] = dp[i][j][1];
            dp[i + 1][j][1] = dp[i][j][0] + a[i];
            if (j > 0)
                dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j - 1][0]);
        }
    }
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //         cout << dp[n][i][j] << " ";
    //     cout << endl;
    // }
    if (n % 2 == 0)
        cout << max(dp[n][1][1], dp[n][0][0]) << endl;
    else
        cout << max(dp[n][2][1], dp[n][1][0]) << endl;
}