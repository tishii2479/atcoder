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
    string s1, s2;
    cin >> s1 >> s2;
    ll ans = 1;
    int last = 3;
    for (int i = 0; i < n; i++) {
        if (s1[i] == s2[i]) {
            ans *= last;
            ans %= MOD;
            last = 2;
            continue;
        }
        if (last == 1) {
            ans *= 3;
            ans %= MOD;
            i++;
            continue;
        }
        ans *= last;
        ans %= MOD;
        last--;
        ans *= last;
        ans %= MOD;
        last = 1;
        i++;
    }
    cout << ans << endl;
}