#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
// #define MOD 998244353
const ll INF = 1LL << 60;
int main() {
    int n, m;
    ll l;
    cin >> n >> m >> l;
    ll dist[310][310];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            dist[i][j] = INF;
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--, b--;
        dist[a][b] = dist[b][a] = c;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
    ll nw[310][310];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            nw[i][j] = (dist[i][j] <= l ? 1 : INF);
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                nw[j][k] = min(nw[j][k], nw[j][i] + nw[i][k]);
    int q;
    cin >> q;
    while (q--) {
        int s, t;
        cin >> s >> t;
        s--, t--;
        cout << (nw[s][t] < INF ? nw[s][t] - 1 : -1) << endl;
    }
}