#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;

using mint = atcoder::modint998244353;

int main() {
    using ll = long long;
    ll n;
    cin >> n;

    mint ans = 0;
    for (ll i = 1; i * i <= n; i++) {
        ll cnt = (n / i - i + 2) / 2;
        ans += cnt;
    }
    cout << ans.val() << endl;
}
