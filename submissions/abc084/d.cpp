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
    int q;
    cin >> q;
    vector<int> l(q), r(q);
    for (int i = 0; i < q; i++)
        cin >> l[i] >> r[i];
    vector<int> cnt(110000, 0);
    vector<bool> isOk(110000, false);
    sieve(110000);
    for (int i = 0; i < 110000; i++) {
        if (i % 2 == 0)
            continue;
        if (isPrime[i] and isPrime[(i + 1) / 2])
            isOk[i] = true;
    }
    for (int i = 0; i + 1 < 110000; i++) {
        cnt[i + 1] = cnt[i] + isOk[i];
    }
    vector<int> res(q);
    for (int i = 0; i < q; i++) {
        res[i] = cnt[r[i] + 1] - cnt[l[i]];
    }
    for (int r : res)
        cout << r << endl;
}