#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> edges[210000];
    for (int i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        edges[x].push_back(y);
    }
    vector<ll> dp(210000, INF);
    for (int i = 0; i < n; i++) {
        for (int u : edges[i]) {
            dp[u] = min({dp[i], dp[u], a[i]});
        }
    }
    ll ans = -INF;
    for (int i = 0; i < n; i++) {
        ans = max(ans, a[i] - dp[i]);
    }
    cout << ans << endl;
}