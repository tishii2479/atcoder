#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 29;
const int MOD = 1000000007;
// const int MOD = 998244353;
int solve(ll h, ll w) {
    if (h % 3 == 0 or w % 3 == 0)
        return 0;
    ll ans = INF;
    for (ll y = 1; y < h; y++) {
        if (w % 2 != 0) {
            ll ret1 = y * w - (w / 2) * (h - y);
            ll ret2 = y * w - (w / 2 + 1) * (h - y);
            ans = min(ans, max(abs(ret1), abs(ret2)));
        } else {
            ans = min(ans, abs(y * w - (w / 2) * (h - y)));
        }
        if ((h - y) % 2 != 0) {
            ll ret1 = y * w - ((h - y) / 2) * w;
            ll ret2 = y * w - ((h - y) / 2 + 1) * w;
            ans = min(ans, max(abs(ret1), abs(ret2)));
        } else {
            ans = min(ans, abs(y * w - ((h - y) / 2) * w));
        }
    }
    ll temp = h;
    h = w;
    w = temp;
    for (ll y = 1; y < h; y++) {
        if (w % 2 != 0) {
            ll ret1 = y * w - (w / 2) * (h - y);
            ll ret2 = y * w - (w / 2 + 1) * (h - y);
            ans = min(ans, max(abs(ret1), abs(ret2)));
        } else {
            ans = min(ans, abs(y * w - (w / 2) * (h - y)));
        }
        if ((h - y) % 2 != 0) {
            ll ret1 = y * w - ((h - y) / 2) * w;
            ll ret2 = y * w - ((h - y) / 2 + 1) * w;
            ans = min(ans, max(abs(ret1), abs(ret2)));
        } else {
            ans = min(ans, abs(y * w - ((h - y) / 2) * w));
        }
    }
    return ans;
}
int main() {
    int h, w;
    cin >> h >> w;
    cout << solve(h, w) << endl;
}