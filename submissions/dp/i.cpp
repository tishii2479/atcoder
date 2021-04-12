#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define each(i, mp) for (auto &i : mp)
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repd(i, n) for (ll i = n - 1; i >= 0; i--)
#define MOD 1000000007
// #define MOD 998244353
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
double dp[3100][3100];
int main() {
    int n;
    cin >> n;
    vector<double> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (j > 0)
                dp[i][j] += dp[i - 1][j - 1] * p[i];
            dp[i][j] += dp[i - 1][j] * (1 - p[i]);
        }
    }
    double ans = 0;
    for (int i = 0; i <= n; i++) {
        if (i <= n / 2) continue;
        ans += dp[n][i];
    }
    printf("%.15lf\n", ans);
}