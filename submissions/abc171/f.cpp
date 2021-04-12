#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
vector<long long> fact, fact_inv, inv;
/*  init_nCk :二項係数のための前処理
    計算量:O(n)
*/
void init_nCk(int SIZE) {
    fact.resize(SIZE + 5);
    fact_inv.resize(SIZE + 5);
    inv.resize(SIZE + 5);
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < SIZE + 5; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
    }
}
/*  nCk :MODでの二項係数を求める(前処理 int_nCk が必要)
    計算量:O(1)
*/
long long nCk(int n, int k) {
    assert(!(n < k));
    assert(!(n < 0 || k < 0));
    return fact[n] * (fact_inv[k] * fact_inv[n - k] % MOD) % MOD;
}
ll modpow(ll m, ll n) {
    if (n == 1)
        return m;
    if (n == 0)
        return 1;
    ll res;
    ll t = modpow(m, n / 2);
    ll tmp;
    if (n % 2 == 0) {
        tmp = (t * t) % MOD;
    } else {
        tmp = (((t * t) % MOD) * m) % MOD;
    }
    return tmp;
}
int main() {
    ll k;
    string s;
    cin >> k >> s;
    ll n = s.length();
    init_nCk(2100000);
    ll ans = 0;
    for (ll i = n; i <= n + k; i++) {
        // cout << i - 1 << " " << n - 1 << " " << n + k - i << endl;
        // cout << nCk(i - 1, n - 1) << " " << modpow(25, i - n) << " " << modpow(26, n + k - i) << endl;
        ans += ((nCk(i - 1, n - 1) * modpow(25, i - n) % MOD) * modpow(26, n + k - i) % MOD);
        ans %= MOD;
        // cout << ans << endl;
    }
    cout << ans << endl;
}