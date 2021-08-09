#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;

/*

x^n = y (mod P)
r := root of p
r^a = x (1 <= a <= p - 1)
r^b = y (1 <= b <= p - 1)

r^an = r^b
an = b (mod p - 1)
s.t. (1 <= a, b <= p - 1)

*/

long long gcd(long long a, long long b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int main() {
    using mint = atcoder::modint998244353;
    using ll = long long;

    ll p;
    cin >> p;

    vector<ll> dividers;

    for (ll i = 1; i * i <= p - 1; i++) {
        if ((p - 1) % i == 0) {
            dividers.push_back(i);
            if (i * i != p - 1) {
                dividers.push_back((p - 1) / i);
            }
        }
    }

    sort(dividers.begin(), dividers.end(), greater<ll>());

    map<ll, mint> mp;
    mint ans = 1;

    for (auto div : dividers) {
        ll g = div;
        mint cnt = (p - 1) / g;
        for (auto m : mp) {
            if (m.first % g == 0) {
                cnt -= m.second;
            }
        }
        ans += cnt * (p - 1) / g;
        mp[div] = cnt;
    }

    cout << ans.val() << endl;
}
