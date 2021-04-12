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
int main() {
    int n, k, r, s, p;
    cin >> n >> k >> r >> s >> p;
    string t;
    cin >> t;
    ll ans = 0;
    vector<char> c(n);
    for (int i = 0; i < n; i++) {
        if (i < k) {
            if (t[i] == 'r') {
                ans += p;
                c[i] = 'p';
            } else if (t[i] == 's') {
                ans += r;
                c[i] = 'r';
            } else {
                ans += s;
                c[i] = 's';
            }
            continue;
        }
        if (t[i] == 'r') {
            if (c[i - k] == 'p') {
                if (i + k < n) {
                    c[i] = t[i + k];
                } else
                    c[i] = 'p';
            } else {
                ans += p;
                c[i] = 'p';
            }
        } else if (t[i] == 's') {
            if (c[i - k] == 'r') {
                if (i + k < n) {
                    c[i] = t[i + k];
                } else
                    c[i] = 'r';
            } else {
                ans += r;
                c[i] = 'r';
            }
        } else {
            if (c[i - k] == 's') {
                if (i + k < n) {
                    c[i] = t[i + k];
                } else
                    c[i] = 's';
            } else {
                ans += s;
                c[i] = 's';
            }
        }
    }
    cout << ans << endl;
}