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
    ll n, k;
    cin >> n >> k;
    vector<ll> s(n);
    bool flag = false;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (s[i] == 0)
            flag = true;
    }
    if (flag) {
        cout << n << endl;
        return 0;
    }
    ll now = 1;
    ll cnt = 0;
    ll ans = 0;
    ll l = 0;
    for (int i = 0; i < n; i++) {
        now *= s[i];
        cnt++;
        if (now <= k) {
        } else {
            while (now > k and l <= i) {
                now /= s[l];
                l++;
                cnt--;
            }
        }
        chmax(ans, cnt);
    }
    cout << ans << endl;
}