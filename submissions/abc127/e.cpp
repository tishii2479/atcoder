#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
const int MOD = (int)(1e9) + 7;
vector<ll> fact, fact_inv, inv;
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
ll nCk(int n, int k) {
    assert(!(n < k));
    assert(!(n < 0 || k < 0));
    return fact[n] * (fact_inv[k] * fact_inv[n - k] % MOD) % MOD;
}
ll nPk(int n, int k) {
    assert(!(n < k));
    assert(!(n < 0 || k < 0));
    return fact[n] * fact_inv[n - k] % MOD;
}
int main() {
    using mint = modint1000000007;
    ll n, m, k;
    cin >> n >> m >> k;
    init_nCk(210000);
    mint ans = 0;
    vector<mint> xsums(210000, 0);
    for (ll i = 0; i < 201000; i++)
        xsums[i + 1] = xsums[i] + (i + 1) * m;
    vector<mint> ysums(210000, 0);
    for (ll i = 0; i < 201000; i++)
        ysums[i + 1] = ysums[i] + (i + 1) * n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            mint dx = xsums[i] + xsums[n - i - 1];
            mint dy = ysums[j] + ysums[m - j - 1];
            ans += (dx + dy) * nCk(n * m - 2, k - 2);
            // cout << dx.val() << " " << dy.val() << " " << nCk(n * m - 2, k - 2) << endl;
        }
    cout << (ans / 2).val() << endl;
}