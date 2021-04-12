#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
using ll = long long;
ll n, m;
const int MOD = 998244353;
const int N = 15;
mint ans = 0;
bool seen[N][5100];
mint memo[N][5100];
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
mint dfs(int cur, ll sum, mint p) {
    if (cur == -1) {
        if (sum == m) {
            ans += p;
            return p;
        }
        return 0;
    }
    if (seen[cur][sum]) {
        ans += memo[cur][sum].val() * p;
        return memo[cur][sum].val() * p;
    }
    mint s = 0;
    for (int i = 0; i <= n and (1 << cur) * i + sum <= m; i += 2) {
        mint pp = dfs(cur - 1, sum + (1 << cur) * i, p * nCk(n, i));
        s += pp;
    }
    memo[cur][sum] = s / p;
    seen[cur][sum] = true;
    return s;
}
ll solve() {
    if (m % 2 == 1)
        return 0;
    init_nCk(5500);
    dfs(14, 0, 1);
    return ans.val();
}
int main() {
    cin >> n >> m;
    cout << solve() << endl;
}