#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;

using mint = atcoder::modint998244353;

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
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    map<int, int> mp;
    for (int i = 0; i < n; i++) mp[c[i]]++;

    map<int, int> cnt;
    for (auto m : mp) cnt[m.second]++;

    init_nCk(110000);

    for (int k = 1; k <= n; k++) {
        mint ans = 0;

        for (auto m : cnt) {
            if (n - m.first < k) {
                ans += m.second;
            } else {
                ans += (mint(nCk(n, k)) - nCk(n - m.first, k)) / nCk(n, k) * m.second;
            }
        }

        cout << ans.val() << endl;
    }
}
