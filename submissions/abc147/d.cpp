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
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll res = 0;
    ll two = 1;
    for (int d = 0; d < 60; d++) {
        ll even = 0, odd = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] & (1LL << d))
                odd++;
            else
                even++;
        }
        ll add = (odd * even) % MOD * two % MOD;
        res += add;
        res %= MOD;
        two *= 2;
        two %= MOD;
    }
    cout << res << endl;
}