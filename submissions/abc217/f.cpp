#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

using ll = long long;
const int MOD = 998244353;
using ll = long long;
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
    using mint = atcoder::modint998244353;

    init_nCk(1000);

    int n, m;
    cin >> n >> m;
    n *= 2;

    vector<vector<bool>> edges(n, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a][b] = edges[b][a] = true;
    }

    vector<vector<mint>> dp(n + 1, vector<mint>(n + 1, 0));
    for (int i = 0; i <= n; i++) dp[i][i] = 1;

    for (int w = 2; w <= n; w += 2) {
        for (int l = 0; l + w <= n; l++) {
            int r = l + w;
            // l and r
            if (edges[l][l + 1]) dp[l][r] += dp[l + 2][r] * nCk(w / 2, 1);

            for (int k = l + 3; k + 1 <= r; k += 2) {
                if (edges[l][k] == false) continue;
                dp[l][r] += dp[l + 1][k] * dp[k + 1][r] * nCk(w / 2, (k - l + 1) / 2);
            }

            // cout << l << " " << r << " " << dp[l][r].val() << endl;
        }
    }

    cout << dp[0][n].val() << endl;
}
