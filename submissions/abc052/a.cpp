#include <bits/stdc++.h>
using namespace std;
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
int main() {
    ll n;
    cin >> n;
    sieve(1100);
    ll ans = 1;
    for (ll i = 2; i <= 1000; i++) {
        ll cnt = 0;
        ll tmp = n;
        if (isPrime[i] == false)
            continue;
        while (tmp > 0) {
            cnt += tmp / i;
            tmp /= i;
        }
        ans *= (cnt + 1);
        ans %= MOD;
    }
    cout << ans << endl;
}