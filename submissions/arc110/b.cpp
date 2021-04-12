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
int main() {
    ll n;
    string t;
    cin >> n >> t;
    ll ans = 0;
    ll j = 0;
    string s = "110110";
    for (int i = 0; i < 3; i++) {
        bool flag = true;
        for (j = 0; j < n; j++) {
            if (t[j] != s[(j + i) % 3]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            if ((i + n) % 3 == 0) {
                ans = 10000000000 - (i + n) / 3 + 1;
            } else {
                ans = 10000000000 - (i + n) / 3;
            }
        }
    }
    if (t == "1")
        ans = 20000000000;
    cout << ans << endl;
}