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
    int n;
    cin >> n;
    int sum = 0;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    int p;
    if (sum % n == 0) {
        p = sum / n;
    } else {
        if ((double)sum / n - sum / n < 0.5) {
            p = sum / n;
        } else {
            p = sum / n + 1;
        }
    }
    ll ans = 0;
    rep(i, n) {
        ans += (p - a[i]) * (p - a[i]);
    }
    cout << ans << endl;
}