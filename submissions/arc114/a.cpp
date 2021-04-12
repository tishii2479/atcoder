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
// エラトステネス
vector<bool> isPrime;
void sieve(size_t max) {
    if (max + 1 > isPrime.size()) {     // resizeで要素数が減らないように
        isPrime.resize(max + 1, true);  // isPrimeに必要な要素数を確保
    }
    isPrime[0] = false;                            // 0は素数ではない
    isPrime[1] = false;                            // 1は素数ではない
    for (size_t i = 2; i * i <= max; ++i)          // 0からsqrt(max)まで調べる
        if (isPrime[i])                            // iが素数ならば
            for (size_t j = 2; i * j <= max; ++j)  // (max以下の)iの倍数は
                isPrime[i * j] = false;            // 素数ではない
}
ll gcd(ll a, ll b) {
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
int main() {
    int n;
    cin >> n;
    vector<ll> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    sieve(60);
    vector<ll> primes;
    for (int i = 2; i <= 50; i++)
        if (isPrime[i])
            primes.push_back(i);
    ll ans = INF;
    int size = primes.size();
    for (int bit = 0; bit < (1 << size); bit++) {
        ll cur = 1;
        for (int i = 0; i < size; i++)
            if (bit & (1 << i))
                cur *= primes[i];
        bool flag = true;
        for (int i = 0; i < n; i++)
            if (gcd(x[i], cur) == 1)
                flag = false;
        if (flag)
            ans = min(ans, cur);
    }
    cout << ans << endl;
}