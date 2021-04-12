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
ll gcd(ll a, ll b) {
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> lgcd(n + 1);
    vector<ll> rgcd(n + 1);
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            lgcd[i + 1] = gcd(a[i], lgcd[i]);
            rgcd[i + 1] = gcd(a[n - i - 1], rgcd[i]);
        } else {
            lgcd[i + 1] = a[i];
            rgcd[i + 1] = a[n - i - 1];
        }
    }
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        ll val;
        if (i == 0) {
            val = rgcd[n - i - 1];
        } else if (i == n - 1) {
            val = lgcd[i];
        } else {
            val = gcd(lgcd[i], rgcd[n - i - 1]);
        }
        if (val > 1000000000 or val < 1) {
            continue;
        }
        chmax(ans, val);
    }
    cout << ans << endl;
}