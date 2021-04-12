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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<ll> sums(n + 1);
    sums[0] = 0;
    for (int i = 1; i <= n; i++) {
        sums[i] = sums[i - 1] + a[i - 1];
        // cout << a[i] << endl;
    }
    ll ans = 0;
    for (int i = 1; i <= n - 1; i++) {
        ans += sums[n] - sums[i] - a[i - 1] * (n - i);
    }
    cout << ans << endl;
}