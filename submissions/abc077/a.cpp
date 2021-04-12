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
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
        cin >> b[i];
    for (ll i = 0; i < n; i++)
        cin >> c[i];
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());
    sort(c.begin(), c.end(), greater<ll>());
    vector<ll> bcnt(n);
    for (ll i = 0; i < n; i++) {
        ll l = -1, r = n;
        while (r - l > 1) {
            ll m = (r + l) / 2;
            bool ok = b[i] < c[m];
            if (ok)
                l = m;
            else
                r = m;
        }
        bcnt[i] = l + 1;
    }
    vector<ll> bsum(n + 1, 0);
    for (ll i = 0; i < n; i++)
        bsum[i + 1] = bsum[i] + bcnt[i];
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ll l = -1, r = n;
        while (r - l > 1) {
            ll m = (r + l) / 2;
            bool ok = a[i] < b[m];
            if (ok)
                l = m;
            else
                r = m;
        }
        ans += bsum[l + 1];
    }
    cout << ans << endl;
}