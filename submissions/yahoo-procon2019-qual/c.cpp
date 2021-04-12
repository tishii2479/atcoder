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
int main() {
    ll k, a, b;
    cin >> k >> a >> b;
    ll ans;
    if (k + 1 <= a) {
        ans = k + 1;
    } else if (b - a > 2) {
        ll cur = 1;
        k -= a - 1;
        cur = a;
        ll cnt = k / 2;
        if (k % 2 == 1)
            cur++;
        cur += (b - a) * cnt;
        ans = cur;
    } else {
        ans = k + 1;
    }
    cout << ans << endl;
}