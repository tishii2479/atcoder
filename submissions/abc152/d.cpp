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
ll cnt[10][10];
int main() {
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int b = i % 10;
        int a = i % 10;
        int j = i;
        while (j >= 10) {
            j /= 10;
            a = j % 10;
        }
        cnt[a][b]++;
    }
    ll ans = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            ans += cnt[i][j] * cnt[j][i];
        }
    }
    cout << ans << endl;
}