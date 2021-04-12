#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
// const int MOD = 1000000007;
const int MOD = 998244353;
const int MAX = 210000;
ll fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数計算
ll COM(int n, int k) {
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
vector<ll> memo(210000, 0);
ll modpow(ll m, ll n) {
    if (memo[n] != 0)
        return memo[n];
    if (n == 1)
        return m;
    if (n == 0)
        return 1;
    ll res;
    ll t = modpow(m, n / 2);
    if (n % 2 == 0) {
        memo[n] = t * t;
    } else {
        memo[n] = ((t * t) % MOD) * m;
    }
    memo[n] %= MOD;
    return memo[n];
}
int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    COMinit();
    ll res = 0;
    for (int i = 0; i <= k; i++) {
        res += ((m * modpow(m - 1, n - i - 1)) % MOD) * COM(n - 1, i);
        res %= MOD;
    }
    cout << res << endl;
}