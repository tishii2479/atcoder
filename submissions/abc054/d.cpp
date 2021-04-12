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
struct S {
    int a, b, c;
};
int main() {
    int n, ma, mb;
    cin >> n >> ma >> mb;
    vector<S> v(n);
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[i] = {a, b, c};
    }
    // dp[ai][bi] := minimum cost dp
    vector<vector<int>> dp(410, vector<int>(410, inf));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 400; j >= 0; j--)
            for (int k = 400; k >= 0; k--)
                if (j - v[i].a >= 0 and k - v[i].b >= 0)
                    dp[j][k] = min(dp[j][k], dp[j - v[i].a][k - v[i].b] + v[i].c);
    int ans = inf;
    for (int i = 0; i <= 400; i++)
        for (int j = 0; j <= 400; j++)
            if (i * mb == j * ma and i != 0 and j != 0)
                ans = min(ans, dp[i][j]);
    if (ans == inf)
        ans = -1;
    cout << ans << endl;
}