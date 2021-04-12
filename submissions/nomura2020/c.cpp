#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 0; i < n + 1; i++)
        cin >> a[i];
    if (n == 0) {
        if (a[0] == 1)
            cout << 1 << endl;
        else
            cout << -1 << endl;
        return 0;
    }
    if (a[0] != 0) {
        cout << -1 << endl;
        return 0;
    }
    // vector<ll> down(n + 1);
    // down[0] = 1;
    // for (ll d = 0; d < n; d++)
    // {
    //     down[d + 1] = (down[d] - a[d]) * 2;
    //     if (down[d + 1] <= 0)
    //     {
    //         cout << -1 << endl;
    //         return 0;
    //     }
    // }
    // vector<ll> up(n + 1);
    // up[n] = a[n];
    // for (ll d = n - 1; d >= 0; d--)
    // {
    //     up[d] = up[d + 1] + a[d];
    // }
    // for (int i = 0; i <= n; i++)
    // {
    //     cout << down[i] << " " << up[i] << endl;
    // }
    // for (ll d = n; d >= 0; d--)
    // {
    //     ans += min(up[d], down[d]);
    // }
    ll total = 0;
    for (int i = 0; i <= n; i++)
        total += a[i];
    ll cur = 1;
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        cur *= 2;
        if (cur < a[i]) {
            cout << -1 << endl;
            return 0;
        }
        ans += min(cur, total);
        cur = min(cur, total) - a[i];
        total -= a[i];
    }
    cout << ans << endl;
}