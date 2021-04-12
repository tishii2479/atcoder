#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
struct S {
    ll from, to, cost;
};
int main() {
    ll n, m, p;
    cin >> n >> m >> p;
    vector<S> edges(m);
    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        c = p - c;
        edges[i] = S{a, b, c};
    }
    vector<ll> dist(n, INF);
    ll tmp;
    dist[0] = 0;
    for (int i = 0; i < 2 * n; i++) {
        for (auto e : edges) {
            if (dist[e.from] != INF and dist[e.to] > dist[e.from] + e.cost) {
                dist[e.to] = dist[e.from] + e.cost;
                if (i >= n)
                    dist[e.to] = -INF;
            }
        }
        if (i == n - 1)
            tmp = dist[n - 1];
    }
    if (tmp == dist[n - 1])
        cout << max(0LL, -tmp) << endl;
    else
        cout << -1 << endl;
}