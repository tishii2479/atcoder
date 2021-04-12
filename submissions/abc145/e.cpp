#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int dp1[3100][3100];
int dp2[3100][3100];
int main() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    dp1[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < t; j++) {
            dp1[i][j] = dp1[i - 1][j];
            if (j - a[i - 1] >= 0) {
                dp1[i][j] = max(dp1[i][j], dp1[i - 1][j - a[i - 1]] + b[i - 1]);
            }
        }
    }
    dp2[n + 1][0] = 0;
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < t; j++) {
            dp2[i][j] = dp2[i + 1][j];
            if (j - a[i - 1] >= 0) {
                dp2[i][j] = max(dp2[i][j], dp2[i + 1][j - a[i - 1]] + b[i - 1]);
            }
        }
    }
    int ans = max(dp1[n][t - 1], dp2[1][t - 1]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < t - 1; j++) {
            ans = max(ans, dp1[i][j] + b[i] + dp2[i + 2][t - 1 - j]);
        }
    }
    cout << ans << endl;
}