#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
vector<int> edges[110000];
vector<vector<ll>> dp(110000, vector<ll>(3, INF));
void bfs(int v, ll cur) {
    queue<pll> que;
    que.push({v, cur});
    dp[v][0] = 0;
    while (que.empty() == false) {
        pll p = que.front();
        que.pop();
        int v = p.first;
        ll d = p.second;
        for (int u : edges[v]) {
            ll nxt = d + 1;
            if (dp[u][nxt % 3] > dp[v][d % 3] + 1) {
                dp[u][nxt % 3] = nxt;
                que.push({u, nxt});
            }
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
    }
    int s, t;
    cin >> s >> t;
    s--, t--;
    bfs(s, 0);
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    if (dp[t][0] == INF) {
        cout << -1 << endl;
    } else {
        cout << dp[t][0] / 3 << endl;
    }
}