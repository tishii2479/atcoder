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
int main() {
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    ll cnts[110000];
    for (ll i = k; i >= 1; i--) {
        ll cnt = (modpow(k / i, n));
        for (ll j = 2; i * j <= k; j++) {
            cnt -= cnts[i * j];
        }
        cnts[i] = cnt;
        ans += cnt * i;
        ans %= MOD;
        // cout << ans << endl;
    }
    cout << (ans + MOD) % MOD << endl;
}