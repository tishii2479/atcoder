#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    using mint = modint1000000007;
    vector<mint> dp(1 << n, 0);
    dp[0] = 1;
    for (int bit = 0; bit < (1 << n); bit++) {
        int i = __builtin_popcount(bit);
        for (int w = 0; w < n; w++)
            if ((bit & (1 << w)) and a[i - 1][w])
                dp[bit] += dp[bit ^ (1 << w)];
    }
    cout << dp[(1 << n) - 1].val() << endl;
}