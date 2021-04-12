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
int main() {
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    if (k % 2 == 1) {
        ans += (n / k) * (n / k) * (n / k);
    } else {
        ans += (n / k) * (n / k) * (n / k);
        ll a = (n + k / 2) / k;
        ans += a * a * a;
    }
    cout << ans << endl;
}