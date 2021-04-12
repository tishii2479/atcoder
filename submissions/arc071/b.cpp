#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> x(n);
    vector<ll> y(m);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < m; i++)
        cin >> y[i];
    vector<ll> dx(n - 1);
    vector<ll> dy(m - 1);
    for (int i = 0; i < n - 1; i++)
        dx[i] = x[i + 1] - x[i];
    for (int i = 0; i < m - 1; i++)
        dy[i] = y[i + 1] - y[i];
    ll xsum = 0;
    ll ysum = 0;
    for (int i = 0; i < n - 1; i++) {
        xsum += dx[i] * (i + 1) * (n - 1 - i);
        xsum %= MOD;
        // cout << i << " " << dx[i] << endl;
    }
    for (int i = 0; i < m - 1; i++) {
        ysum += dy[i] * (i + 1) * (m - 1 - i);
        ysum %= MOD;
        // cout << i << " " << dy[i] << " " << (i + 1) * (m - 1 - i) << endl;
    }
    ll ans = xsum * ysum;
    ans %= MOD;
    cout << ans << endl;
}