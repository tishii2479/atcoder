#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
// const int MOD = 1000000007;
const int MOD = 998244353;
ll modpow(ll m, ll n) {
    if (n == 0)
        return 1;
    ll t = modpow(m, n / 2);
    if (n % 2 == 0)
        return (t * t) % MOD;
    else
        return (((t * t) % MOD) * m) % MOD;
}
int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll ans = 0;
    if (n == 1) {
        for (ll i = 1; i <= k; i++) {
            ans += modpow(k - i + 1, m) - modpow(k - i, m);
        }
        cout << ((ans % MOD) + MOD) % MOD << endl;
        return 0;
    } else if (m == 1) {
        for (ll i = 1; i <= k; i++) {
            ans += modpow(i, n) - modpow(i - 1, n);
        }
        cout << ((ans % MOD) + MOD) % MOD << endl;
        return 0;
    }
    for (ll i = 1; i <= k; i++) {
        ll a = modpow(i, n);
        ll b = (modpow(k - i + 1, m) - modpow(k - i, m)) % MOD;
        // cout << i << " " << a << " " << b << endl;
        a *= b;
        a %= MOD;
        ans += a;
        ans %= MOD;
    }
    cout << ((ans % MOD) + MOD) % MOD << endl;
}