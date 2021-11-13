#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;

// const int MOD = 1000000007;
const int MOD = 998244353;
using ll = long long;
vector<ll> fact, fact_inv, inv;

void init_nCk(const int n) {
    fact.resize(n + 5);
    fact_inv.resize(n + 5);
    inv.resize(n + 5);
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < n + 5; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
    }
}

ll nCk(const int n, const int k) {
    assert(!(n < k));
    assert(!(n < 0 || k < 0));
    return fact[n] * (fact_inv[k] * fact_inv[n - k] % MOD) % MOD;
}

ll nPk(const int n, const int k) {
    assert(!(n < k));
    assert(!(n < 0 || k < 0));
    return fact[n] * fact_inv[n - k] % MOD;
}

using mint = atcoder::modint998244353;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    init_nCk(1100);

    vector<mint> sums(310);
    for (int i = 0; i < 310; i++) {
        for (int j = 0; j < n; j++) {
            sums[i] += mint(a[j]).pow(i);
        }
    }

    for (int x = 1; x <= k; x++) {
        mint ans = 0;

        for (int i = 0; i <= x; i++) {
            ans += sums[x - i] * sums[i] * nCk(x, i);
            ans -= sums[x] * nCk(x, i);
        }

        cout << (ans / 2).val() << endl;
    }
}
