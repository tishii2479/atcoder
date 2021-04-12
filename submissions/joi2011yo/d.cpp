#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<ll>> dp(n, vector<ll>(21, 0));
    dp[1][a[0]] = 1;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j <= 20; j++) {
            if (j - a[i] >= 0)
                dp[i + 1][j] += dp[i][j - a[i]];
            if (j + a[i] <= 20)
                dp[i + 1][j] += dp[i][j + a[i]];
        }
    }
    cout << dp[n - 1][a[n - 1]] << endl;
}