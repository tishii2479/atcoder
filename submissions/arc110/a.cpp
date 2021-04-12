#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define each(i, mp) for (auto &i : mp)
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repd(i, n) for (ll i = n - 1; i >= 0; i--)
const int MOD = 1000000007;
// const int MOD = 998244353;
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
ll gcd(ll a, ll b) {
    if (a % b == 0) {
        return (b);
    } else {
        return (gcd(b, a % b));
    }
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
int main() {
    ll n;
    cin >> n;
    ll ans = 1;
    for (int i = 2; i <= n; i++) {
        ans = lcm(ans, i);
    }
    cout << ans + 1 << endl;
}