#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int n;
vector<int> edges[110000];
void dfs(int v, int d, int pre, vector<int> &dist) {
    dist[v] = d;
    for (int u : edges[v]) {
        if (u == pre)
            continue;
        dfs(u, d + 1, v, dist);
    }
}
int main() {
    int u, v;
    cin >> n >> u >> v;
    u--;
    v--;
    if (u == v) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<int> udist(210000, -1);
    vector<int> vdist(210000, -1);
    udist[u] = 0;
    udist[v] = 0;
    dfs(u, 0, u, udist);
    dfs(v, 0, v, vdist);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        // cout << udist[i] << " " << vdist[i] << endl;
        if (udist[i] < vdist[i])
            ans = max(vdist[i] - 1, ans);
    }
    cout << ans << endl;
}