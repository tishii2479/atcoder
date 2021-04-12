#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> p(m);
    for (ll i = 0; i < m; i++)
        cin >> p[i], p[i]--;
    vector<ll> a(n - 1), b(n - 1), c(n - 1);
    for (ll i = 0; i < n - 1; i++)
        cin >> a[i] >> b[i] >> c[i];
    vector<ll> sums(n, 0);
    for (ll i = 0; i < m - 1; i++) {
        ll l = p[i], r = p[i + 1];
        if (l > r)
            swap(l, r);
        sums[l]++, sums[r]--;
    }
    for (int i = 0; i < n - 1; i++)
        sums[i + 1] += sums[i];
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ll ticket = a[i] * sums[i];
        ll ic = b[i] * sums[i] + c[i];
        ans += min(ticket, ic);
    }
    cout << ans << endl;
}