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
int main() {
    ll n, m, t;
    cin >> n >> m >> t;
    ll a, b;
    ll now = n;
    ll prev_b = 0;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        now -= a - prev_b;
        if (now <= 0) {
            cout << "No" << endl;
            return 0;
        }
        now += b - a;
        now = min(n, now);
        prev_b = b;
    }
    now -= t - b;
    if (now > 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}