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
ll dp[110][110000];
int main() {
    int n;
    ll W;
    cin >> n >> W;
    vector<ll> w(n + 1);
    vector<ll> v(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> w[i + 1] >> v[i + 1];
    }
    for (int j = 0; j < 110000; j++) {
        for (int i = 0; i <= n; i++) {
            if (i == 0) {
                if (j > 0) {
                    dp[i][j] = INF;
                } else {
                    dp[i][j] = 0;
                }
                continue;
            } else {
                dp[i][j] = dp[i - 1][j];
                if (j - v[i] >= 0) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
                }
            }
        }
    }
    int ans;
    for (int i = 0; i < 110000; i++) {
        if (dp[n][i] <= W) {
            ans = i;
        }
    }
    cout << ans << endl;
}