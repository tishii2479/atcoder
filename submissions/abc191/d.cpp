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
    long double x, y, r;
    cin >> x >> y >> r;
    r = nextafter(r, INFINITY);
    ll ans = 0;
    for (ll i = ceil(x - r); i <= floor(x + r); i++) {
        long double d = sqrt(r * r - (x - i) * (x - i));
        ans += floor(y + d) - ceil(y - d) + 1;
    }
    cout << ans << endl;
}