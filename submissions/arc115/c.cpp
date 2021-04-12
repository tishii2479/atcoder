#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
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
/*  divisor(n)
    入力：整数 n
    出力：nのすべての約数
    計算量：O(√n)
*/
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n)
                ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());  // 昇順に並べる
    return ret;
}
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    ll mx = 0;
    for (ll i = 1; i <= n; i++) {
        auto divisors = divisor(i);
        ll cnt = divisors.size();
        mx = max(mx, cnt);
    }
    set<ll> all;
    for (ll i = 1; i <= mx; i++)
        all.insert(i);
    for (ll i = 1; i <= n; i++) {
        auto divisors = divisor(i);
        set<ll> st = all;
        for (auto div : divisors) {
            if (div != i)
                st.erase(a[div]);
        }
        a[i] = *st.begin();
    }
    for (ll i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
}