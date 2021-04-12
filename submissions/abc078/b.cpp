#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n, z, w;
    cin >> n >> z >> w;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(2));
    for (int i = n - 1; i >= 0; i--) {
        dp[i][0] = -inf;
        int y = (i ? a[i - 1] : w);
        dp[i][0] = max(dp[i][0], abs(y - a[n - 1]));
        for (int j = i + 1; j < n; j++)
            dp[i][0] = max(dp[i][0], dp[j][1]);
        dp[i][1] = inf;
        int x = (i ? a[i - 1] : z);
        dp[i][1] = min(dp[i][1], abs(x - a[n - 1]));
        for (int j = i + 1; j < n; j++)
            dp[i][1] = min(dp[i][1], dp[j][0]);
    }
    cout << dp[0][0] << endl;
}