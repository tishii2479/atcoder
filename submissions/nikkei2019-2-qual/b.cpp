#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
#define each(i, mp) for (auto &i : mp)
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repd(i, n) for (ll i = n - 1; i >= 0; i--)
// #define MOD 1000000007
#define MOD 998244353
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
ll mPow(ll x, ll n) {
    ll res = 1;
    for (ll i = 0; i < n; i++) {
        res *= x;
        res %= MOD;
    }
    return res;
}
int depth[110000];
int main() {
    int n;
    cin >> n;
    int root;
    cin >> root;
    depth[0] = 1;
    if (root != 0) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i < n; i++) {
        int d;
        cin >> d;
        d -= root;
        if (d <= 0) {
            cout << 0 << endl;
            return 0;
        }
        depth[d]++;
    }
    if (n == 1) {
        if (root == 0) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    }
    ll ans = 0;
    bool endFlag = false;
    for (int i = 1; i < 101000; i++) {
        if (depth[i] > 0 and endFlag) {
            cout << 0 << endl;
            return 0;
        }
        if (depth[i] == 0) {
            endFlag = true;
            continue;
        }
        if (ans == 0)
            ans = 1;
        ans *= mPow(depth[i - 1], depth[i]);
        ans %= MOD;
    }
    cout << ans << endl;
}