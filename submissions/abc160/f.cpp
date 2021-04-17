#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
using ll = long long;
const int MOD = 1000000007;
const int N = 210000;
vector<vector<int>> edges(N);
vector<int> sz(N);
vector<mint> dp(N);
vector<mint> ans(N);
int n;
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
void dfs1(int v, int par = -1) {
    dp[v] = 1;
    for (int u : edges[v]) {
        if (u == par) continue;
        dfs1(u, v);
        sz[v] += sz[u];
        dp[v] *= dp[u] * nCk(sz[v], sz[u]);
    }
    sz[v]++;
}
void dfs2(int v, mint d_par, int par = -1) {
    ans[v] = dp[v] * d_par * nCk(n - 1, n - sz[v]);
    for (int u : edges[v]) {
        if (u == par) continue;
        dfs2(u, ans[v] / dp[u] / nCk(n - 1, sz[u]), v);
    }
}
int main() {
    cin >> n;
    init_nCk(N);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs1(0);
    dfs2(0, 1);
    for (int i = 0; i < n; i++) cout << ans[i].val() << endl;
}