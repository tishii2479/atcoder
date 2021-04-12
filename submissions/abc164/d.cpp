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
int modpow(int a) {
    int res = 1;
    for (int i = 0; i < a; i++) {
        res *= 10;
        res %= 2019;
    }
    return res;
}
int main() {
    string s;
    cin >> s;
    int t[210000];
    int n = s.length();
    s = ' ' + s;
    t[n] = s[n] - '0';
    int now = 1;
    for (int i = n - 1; i >= 1; i--) {
        now *= 10;
        now %= 2019;
        t[i] = (t[i + 1] + (s[i] - '0') * now) % 2019;
    }
    map<int, int> set;
    for (int i = 1; i <= n; i++) {
        // cout << t[i] << endl;
        set[t[i]]++;
    }
    set[0]++;
    ll ans = 0;
    each(s, set) {
        int m = s.second;
        ans += m * (m - 1) / 2;
    }
    cout << ans << endl;
}