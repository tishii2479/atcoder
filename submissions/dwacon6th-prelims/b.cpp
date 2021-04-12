#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
ll modpow(ll m, ll n) {
    if (n == 0)
        return 1;
    ll t = modpow(m, n / 2);
    if (n % 2 == 0)
        return (t * t) % MOD;
    else
        return (((t * t) % MOD) * m) % MOD;
}
ll inv(ll a) {
    return modpow(a, MOD - 2);
}
int main() {
    int n;
    cin >> n;
    vector<ll> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    vector<ll> diff(n - 1);
    for (int i = 0; i < n - 1; i++)
        diff[i] = (x[i + 1] - x[i]) % MOD;
    ll ans = 0;
    ll fac_n_1 = 1;
    for (ll i = 1; i < n; i++)
        fac_n_1 = (fac_n_1 * i) % MOD;
    ll p[n + 3];
    p[0] = 1;
    for (int i = 0; i < n; i++) {
        p[i + 1] = (p[i] + inv(i + 2)) % MOD;
    }
    for (int i = 0; i < n - 1; i++) {
        ans += (((fac_n_1 * diff[i]) % MOD) * p[i]) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}