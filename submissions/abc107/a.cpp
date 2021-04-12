#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
const int MOD = 1000000007;
// const int MOD = 998244353;
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
    cin >> n >> k;
    vector<ll> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    ll ans = INF;
    for (int l = 0; l + k - 1 < n; l++) {
        int r = l + k - 1;
        if (x[l] * x[r] > 0) {
            chmin(ans, max(abs(x[l]), abs(x[r])));
        } else {
            chmin(ans, abs(x[l]) + abs(x[r]) + min(abs(x[l]), abs(x[r])));
        }
    }
    cout << ans << endl;
}