#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define each(i, mp) for (auto &i : mp)
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repd(i, n) for (ll i = n - 1; i >= 0; i--)
#define MOD 1000000007
// #define MOD 998244353
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
const ll INF = 1LL << 60;
const int inf = 1 << 29;
ll gcd(ll x, ll y) {
    if (x % y == 0)
        return y;
    return gcd(y, x % y);
}
ll lcm(ll x, ll y) {
    return x / gcd(x, y) * y;
}
int main() {
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
        a[i] /= 2;
    }
    while (a[0] % 2 == 0) {
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 != 0) {
                cout << 0 << endl;
                return 0;
            }
            a[i] /= 2;
        }
        m /= 2;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    ll lc = a[0];
    for (int i = 1; i < n; i++) {
        lc = lcm(lc, a[i]);
    }
    ll mx = (m / lc + 1) / 2;
    cout << mx << endl;
}