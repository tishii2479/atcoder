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
int gcd(int a, int b) {
    if (b % a == 0)
        return a;
    return gcd(b, a % b);
}
int main() {
    ll n;
    int k;
    cin >> n;
    cin >> k;
    ll ans = 0;
    while (n > 0) {
        n /= k;
        ans++;
    }
    cout << ans << endl;
}