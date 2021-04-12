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
    int n;
    cin >> n;
    vector<ll> x(n);
    vector<ll> l(n);
    vector<pair<ll, int>> rRank(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> l[i];
        rRank[i] = {x[i] + l[i], i};
    }
    sort(rRank.begin(), rRank.end());
    ll r = -INF;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int j = rRank[i].second;
        if (x[j] - l[j] >= r) {
            r = rRank[i].first;
            cnt++;
        }
    }
    cout << cnt << endl;
}