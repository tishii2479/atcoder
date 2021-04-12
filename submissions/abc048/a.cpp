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
int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        if (i == 0 and a[i] > x) {
            ans += a[i] - x;
            a[i] = x;
        }
        if (a[i] + a[i + 1] > x) {
            ans += (a[i] + a[i + 1] - x);
            a[i + 1] -= (a[i] + a[i + 1] - x);
        }
    }
    if (n % 2 == 1 and a[n - 1] > x) {
        ans += a[n - 1] - x;
    }
    cout << ans << endl;
}