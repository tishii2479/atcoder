#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 28;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dist(n, vector<int>(n, inf));
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        a--, b--;
        dist[a][b] = dist[b][a] = t;
    }
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //         cout << dist[i][j] << " ";
    //     cout << endl;
    // }
    int mn = inf;
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 0; j < n; j++)
            cur = max(cur, dist[i][j]);
        mn = min(mn, cur);
    }
    cout << mn << endl;
}