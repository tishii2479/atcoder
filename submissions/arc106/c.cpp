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
    int n, m;
    cin >> n >> m;
    if (n == 1 and m == 0) {
        cout << 1 << " " << 2 << endl;
        return 0;
    }
    if (m < 0 or m > n - 2) {
        cout << -1 << endl;
        return 0;
    }
    int l = 1;
    int r = 4 + m * 2;
    cout << l << " " << r << endl;
    for (int i = 1; i <= m + 1; i++) {
        cout << i * 2 << " " << i * 2 + 1 << endl;
    }
    for (int i = m + 2; i < n; i++) {
        cout << i * 2 + 1 << " " << i * 2 + 2 << endl;
    }
}