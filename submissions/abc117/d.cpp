#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll dp[100][2];
    for (int i = 0; i <= 60; i++)
        dp[i][0] = dp[i][1] = -1;
    dp[60][0] = 0;
    for (ll i = 59; i >= 0; i--) {
        ll mask = (1LL << i);
        ll num = 0;
        for (int j = 0; j < n; j++)
            if (a[j] & mask)
                num++;
        if (dp[i + 1][1] >= 0) {
            dp[i][1] = max(dp[i][1], dp[i + 1][1] + mask * max(num, n - num));
        }
        if (dp[i + 1][0] >= 0) {
            if (k & (1LL << i)) {
                dp[i][1] = max(dp[i][1], dp[i + 1][0] + mask * num);
                dp[i][0] = max(dp[i][0], dp[i + 1][0] + mask * (n - num));
            } else {
                dp[i][0] = max(dp[i][0], dp[i + 1][0] + mask * num);
            }
        }
        // cout << dp[i][0] << " " << dp[i][1] << endl;
    }
    cout << max(dp[0][0], dp[0][1]) << endl;
}