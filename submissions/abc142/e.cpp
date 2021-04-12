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
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> b(m);
    vector<int> c(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        int _c;
        for (int j = 0; j < b[i]; j++) {
            cin >> _c;
            _c--;
            c[i] += 1 << _c;
        }
    }
    vector<vector<int>> dp(1100, vector<int>(5000, inf));
    dp[0][0] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i + 1][j] = min(dp[i][j], dp[i + 1][j]);
            int nj = j | c[i];
            dp[i + 1][nj] = min(dp[i + 1][nj], dp[i][j] + a[i]);
        }
    }
    cout << (dp[m][(1 << n) - 1] < inf ? dp[m][(1 << n) - 1] : -1) << endl;
}