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
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    vector<pll> cb(m);
    for (int i = 0; i < m; i++) {
        ll b, c;
        cin >> b >> c;
        cb[i] = {c, b};
    }
    sort(cb.begin(), cb.end(), greater<pll>());
    ll ans = 0;
    pll next;
    int now = 0;
    int nowInd = 0;
    next = cb[now++];
    for (int i = 0; i < n; i++) {
        if (nowInd == next.second) {
            next = cb[now++];
            nowInd = 0;
        }
        if (a[i] >= next.first)
            break;
        nowInd++;
        a[i] = next.first;
    }
    for (int i = 0; i < n; i++) {
        ans += a[i];
    }
    cout << ans << endl;
}