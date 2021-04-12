#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll res = 0;
    if (c * 2 <= a + b) {
        res += min(x, y) * c * 2;
        if (x > y) {
            ll ak = x - y;
            res += ak * a;
        } else {
            ll bk = y - x;
            res += bk * b;
        }
    } else {
        res = a * x + b * y;
    }
    ll ret = max(x, y) * c * 2;
    cout << min(res, ret) << endl;
}