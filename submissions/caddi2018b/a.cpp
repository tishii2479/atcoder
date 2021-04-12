#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
// 素因数分解
vector<pll> prime_factorize(ll n) {
    vector<pll> res;
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p != 0)
            continue;
        int num = 0;
        while (n % p == 0) {
            ++num;
            n /= p;
        }
        res.push_back(make_pair(p, num));
    }
    if (n != 1)
        res.push_back(make_pair(n, 1));
    return res;
}
int main() {
    ll n, p;
    cin >> n >> p;
    auto primes = prime_factorize(p);
    ll ans = 1;
    for (auto pi : primes) {
        ll pr = pi.first;
        ll cnt = pi.second;
        ll tmp = pr;
        for (ll i = 1; i < (cnt / n); i++)
            pr *= tmp;
        if (cnt >= n)
            ans *= pr;
    }
    cout << ans << endl;
}