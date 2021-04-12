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
    int n, k;
    ll m, r;
    cin >> n >> k >> m >> r;
    vector<ll> s(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> s[i];
    sort(s.begin(), s.end(), greater<ll>());
    ll sum = 0;
    for (int i = 0; i < k - 1; i++) {
        sum += s[i];
    }
    ll ans = r * k - sum;
    if ((n != k and sum + s[k - 1] >= r * k) or ans <= 0) {
        cout << 0 << endl;
    } else if (ans > m) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}