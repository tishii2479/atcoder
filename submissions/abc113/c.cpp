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
    int n, m;
    cin >> n >> m;
    vector<ll> pref[n];
    vector<int> vp(m);
    vector<ll> vy(m);
    ll p, y;
    for (int i = 0; i < m; i++) {
        cin >> p >> y;
        pref[p - 1].push_back(y);
        vp[i] = p - 1;
        vy[i] = y;
    }
    for (int i = 0; i < n; i++) {
        sort(pref[i].begin(), pref[i].end());
    }
    for (int i = 0; i < m; i++) {
        int ind = lower_bound(pref[vp[i]].begin(), pref[vp[i]].end(), vy[i]) - pref[vp[i]].begin();
        printf("%06d%06d\n", vp[i] + 1, ind + 1);
    }
}