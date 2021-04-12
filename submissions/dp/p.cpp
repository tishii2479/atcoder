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
using mint = modint1000000007;
int n;
vector<int> edges[110000];
// 0 = white, 1 = black
vector<vector<mint>> dp(110000, vector<mint>(2, 1));
void dfs(int v, int par) {
    for (int u : edges[v]) {
        if (u == par)
            continue;
        dfs(u, v);
        dp[v][0] *= dp[u][0] + dp[u][1];
        dp[v][1] *= dp[u][0];
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    dfs(0, -1);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i + 1 << ":  ";
    //     for (int j = 0; j < 2; j++)
    //         cout << dp[i][j].val() << " ";
    //     cout << endl;
    // }
    cout << (dp[0][0] + dp[0][1]).val() << endl;
}