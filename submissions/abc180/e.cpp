#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define each(i, mp) for (auto &i : mp)
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repd(i, n) for (ll i = n - 1; i >= 0; i--)
#define MOD 1000000007
// #define MOD 998244353
const ll INF = 1LL << 60;
const int inf = 1 << 29;
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
ll dp[20][1000000];
int main() {
    int n;
    cin >> n;
    vector<ll> X(n), Y(n), Z(n);
    for (int i = 0; i < n; ++i)
        cin >> X[i] >> Y[i] >> Z[i];
    auto dis = [&](int v, int nv) {
        long long add = abs(X[v] - X[nv]) + abs(Y[v] - Y[nv]) + max(0LL, Z[nv] - Z[v]);
        return add;
    };
    vector<vector<ll>> dp(1 << n, vector<ll>(n + 1, INF));
    dp[1][0] = 0;
    for (int bit = 0; bit < (1 << n); bit++) {
        for (int v = 0; v < n; v++) {
            if ((bit & (1 << v)) == false)
                continue;
            for (int nv = 0; nv < n; nv++) {
                if (bit & (1 << nv))
                    continue;
                int nbit = bit | (1 << nv);
                chmin(dp[nbit][nv], dp[bit][v] + dis(v, nv));
            }
        }
    }
    ll res = INF;
    for (int v = 0; v < n; v++)
        chmin(res, dp[(1 << n) - 1][v] + dis(v, 0));
    cout << res << endl;
}