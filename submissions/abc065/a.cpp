#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    ll n, m;
    cin >> n >> m;
    if (abs(n - m) > 1) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    for (ll i = 1; i <= n; i++) {
        ans *= i;
        ans %= MOD;
    }
    for (ll i = 1; i <= m; i++) {
        ans *= i;
        ans %= MOD;
    }
    if (n % 2 == m % 2)
        ans *= 2;
    ans %= MOD;
    cout << ans << endl;
}