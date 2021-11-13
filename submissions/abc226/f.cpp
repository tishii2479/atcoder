#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

using mint = atcoder::modint998244353;
using ll = long long;

mint ans = 0;
int n, k;

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

ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

vector<mint> kaijo(110, 1);

void dfs(int used, int cnt, int prev, ll lc, mint val, map<int, int> mp) {
    if (used == n) {
        mint add = 1;
        // cout << used << " " << cnt << " " << prev << " " << lc << " " << val.val() << endl;
        int remain = n;
        for (auto m : mp) {
            // cout << m.first << " " << m.second << endl;
            add *= kaijo[m.first - 1].pow(m.second) / kaijo[m.second];
            for (int i = 0; i < m.second; i++) {
                add *= nCk(remain, m.first);
                remain -= m.first;
            }
        }
        ans += mint(lc).pow(k) * add;
        // cout << ans.val() << endl;
        return;
    }
    for (int i = prev; i + used <= n; i++) {
        mint val2 = kaijo[max(0, i - 1)] * val;
        if (i + used < n) {
            val2 *= nCk(n - used, i);
        }
        auto mp2 = mp;
        mp2[i]++;
        dfs(used + i, cnt + 1, i, lcm(lc, i), val2, mp2);
    }
}

int main() {
    cin >> n >> k;
    init_nCk(110000);
    for (int i = 0; i + 1 < 100; i++) {
        kaijo[i + 1] = kaijo[i] * (i + 1);
    }

    dfs(0, 0, 1, 1, 1, {});

    cout << ans.val() << endl;
}
