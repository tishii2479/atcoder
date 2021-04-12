#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
// const int MOD = 1000000007;
const ll MOD = 998244353;
ll dp[5100][5100];
char field[5100][5100];
ll modpow(ll m, ll n) {
    if (n == 1)
        return m;
    if (n == 0)
        return 1;
    ll res;
    ll t = modpow(m, n / 2);
    ll tmp;
    if (n % 2 == 0) {
        tmp = (t * t) % MOD;
    } else {
        tmp = (((t * t) % MOD) * m) % MOD;
    }
    return tmp;
}
ll pow(ll a, ll n) {
    ll ret = 1;
    for (; n > 0; n >>= 1, a = a * a % MOD) {
        if (n % 2 == 1) {
            ret = ret * a % MOD;
        }
    }
    return ret;
}
ll inv(ll a) {
    return pow(a, MOD - 2);
}
int main() {
    int h, w, k;
    cin >> h >> w >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        char c;
        cin >> y >> x >> c;
        x--;
        y--;
        field[y][x] = c;
    }
    dp[0][0] = modpow(3, h * w - k);
    ll inv3 = inv(3);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            char c = field[y][x];
            if (c == 'X') {
                dp[y][x + 1] += dp[y][x];
                dp[y + 1][x] += dp[y][x];
            } else if (c == 'R') {
                dp[y][x + 1] += dp[y][x];
            } else if (c == 'D') {
                dp[y + 1][x] += dp[y][x];
            } else {
                dp[y][x + 1] += dp[y][x] * 2 * inv3;
                dp[y + 1][x] += dp[y][x] * 2 * inv3;
            }
            dp[y][x + 1] %= MOD;
            dp[y + 1][x] %= MOD;
        }
    }
    cout << dp[h - 1][w - 1] << endl;
}