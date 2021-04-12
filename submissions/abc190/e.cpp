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
int dist[17][17];
vector<int> bfs(int s) {
    vector<int> distance(110000, inf);
    queue<int> que;
    que.push(s);
    distance[s] = 0;
    while (que.empty() == false) {
        int v = que.front();
        que.pop();
        for (int u : edges[v]) {
            if (distance[v] + 1 < distance[u]) {
                distance[u] = distance[v] + 1;
                que.push(u);
            }
        }
    }
    return distance;
}
int main() {
    int n, m, k;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    cin >> k;
    vector<int> c(k);
    for (int i = 0; i < k; i++) {
        cin >> c[i];
        c[i]--;
    }
    for (int i = 0; i < k; i++) {
        vector<int> distance = bfs(c[i]);
        for (int j = 0; j < k; j++) {
            if (distance[c[j]] == inf) {
                cout << -1 << endl;
                return 0;
            }
            dist[i][j] = distance[c[j]];
        }
    }
    vector<vector<int>> dp(1 << k, vector<int>(k, inf));
    for (int i = 0; i < k; i++) {
        dp[1 << i][i] = 1;
    }
    for (int bits = 0; bits < (1 << k); bits++)
        for (int now = 0; now < k; now++)
            if (bits & (1 << now))
                for (int nxt = 0; nxt < k; nxt++)
                    if ((bits & (1 << nxt)) == false)
                        dp[bits | (1 << nxt)][nxt] = min(dp[bits | (1 << nxt)][nxt], dp[bits][now] + dist[now][nxt]);
    int ans = inf;
    for (int i = 0; i < k; i++) {
        ans = min(ans, dp[(1 << k) - 1][i]);
    }
    cout << ans << endl;
}