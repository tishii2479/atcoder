#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
#define each(i, mp) for (auto &i : mp)
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
const int MOD = 1000000007;
// const int MOD = 998244353;
int dp[8][1 << 8];
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> edges[10];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dp[0][1] = 1;
    for (int s = 0; s < 1 << n; s++) {
        for (int v = 0; v < n; v++) {
            if ((s & (1 << v)) == 0)
                continue;
            int sub = s ^ (1 << v);
            for (int u : edges[v]) {
                if (sub & (1 << u))
                    dp[v][s] += dp[u][sub];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans += dp[i][(1 << n) - 1];
        // cout << ans << endl;
    }
    cout << ans << endl;
}