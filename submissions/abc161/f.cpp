#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int f(ll x) {
    ll res = 0;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            if (i * i == x)
                res++;
            else
                res += 2;
        }
    }
    return res - 1;
}
int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1; i * i <= n; i++) {
        if ((n - 1) % i == 0) {
            // cout << i << " " << (n - 1) / i << endl;
            if (i == (n - 1) / i)
                ans++;
            else
                ans += 2;
        }
    }
    for (ll i = 2; i * i <= n; i++) {
        if (n % i != 0)
            continue;
        ll tmp = n;
        ll a = i;
        ll b = n / i;
        while (tmp % a == 0)
            tmp /= a;
        if ((tmp - 1) % a == 0) {
            // cout << a << endl;
            ans++;
        }
        tmp = n;
        if (b == a)
            continue;
        while (tmp % b == 0)
            tmp /= b;
        if ((tmp - 1) % b == 0) {
            // cout << b << endl;
            ans++;
        }
    }
    cout << ans << endl;
}