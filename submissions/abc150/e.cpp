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
    ll n;
    cin >> n;
    vector<ll> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    sort(c.begin(), c.end(), greater<ll>());
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ans += c[i] * (i + 2);
        ans %= MOD;
    }
    ans *= modpow(2, 2 * n - 2);
    ans %= MOD;
    cout << ans << endl;
}