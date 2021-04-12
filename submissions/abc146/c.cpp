#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
#define each(i, mp) for (auto &i : mp)
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
const int MOD = 1000000007;
// const int MOD = 998244353;
ll d(ll x) {
    ll res = 0;
    while (x > 0) {
        x /= 10;
        res++;
    }
    return res;
}
ll a, b, x;
ll f(ll n) {
    return a * n + b * d(n);
}
int main() {
    cin >> a >> b >> x;
    ll l = 1;
    ll r = 1000000000;
    if (f(l) > x) {
        cout << 0 << endl;
        return 0;
    }
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (f(mid) < x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (f(r) <= x) {
        cout << r << endl;
    } else {
        cout << l << endl;
    }
}