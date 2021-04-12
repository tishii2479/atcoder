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
int cnt[4];
double dp[330][330][330];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    dp[0][0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n; k++) {
                if (i + j + k == 0) {
                    continue;
                }
                double nonzero = i + j + k;
                dp[i][j][k] = (double)n / nonzero;
                if (i - 1 >= 0)
                    dp[i][j][k] += (double)i / nonzero * dp[i - 1][j + 1][k];
                if (j - 1 >= 0)
                    dp[i][j][k] += (double)j / nonzero * dp[i][j - 1][k + 1];
                if (k - 1 >= 0)
                    dp[i][j][k] += (double)k / nonzero * dp[i][j][k - 1];
            }
        }
    }
    printf("%.15lf\n", dp[cnt[3]][cnt[2]][cnt[1]]);
}