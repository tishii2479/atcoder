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
    int n, k;
    cin >> n >> k;
    vector<ll> p(n);
    ll sums[220000];
    sums[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        sums[i + 1] = sums[i] + p[i];
    }
    ll ans = 0;
    for (int i = 0; i + k < n + 1; i++) {
        chmax(ans, sums[i + k] - sums[i]);
    }
    double res = (double)(ans + k) / 2;
    printf("%.15lf\n", res);
}