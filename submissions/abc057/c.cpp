#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
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
int f(ll n) {
    int res = 1;
    while (n / 10 > 0) {
        n /= 10;
        res++;
    }
    return res;
}
int main() {
    ll n;
    cin >> n;
    int ans = inf;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            int a = max(f(i), f(n / i));
            chmin(ans, a);
        }
    }
    cout << ans << endl;
}