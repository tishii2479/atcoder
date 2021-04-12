#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> f(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> f[i];
    sort(a.begin(), a.end());
    sort(f.begin(), f.end(), greater<ll>());
    ll l = 0;
    ll r = INF;
    while (r - l > 0) {
        ll m = (l + r) / 2;
        ll remain = k;
        for (int i = 0; i < n; i++) {
            ll cost = a[i] * f[i];
            if (cost > m) {
                remain -= a[i] - m / f[i];
            }
            if (remain < 0)
                break;
        }
        if (remain >= 0) {
            r = m;
        } else {
            l = m + 1;
        }
        // cout << l << " " << r << endl;
    }
    cout << r << endl;
}