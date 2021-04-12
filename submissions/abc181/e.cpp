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
int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> h(n);
    vector<ll> w(m);
    rep(i, n) cin >> h[i];
    rep(i, m) cin >> w[i];
    sort(h.begin(), h.end());
    ll ans = INF;
    vector<int> sum1((n + 1) / 2), sum2((n + 1) / 2);
    for (int i = 0; i + 1 < n; i += 2)
        sum1[i / 2 + 1] = sum1[i / 2] + h[i + 1] - h[i];
    for (int i = n - 2; i > 0; i -= 2)
        sum2[i / 2] = sum2[i / 2 + 1] + h[i + 1] - h[i];
    int i = 0;
    for (int j = 0; j < m; j++) {
        ll v = w[j];
        int x = lower_bound(h.begin(), h.end(), v) - h.begin();
        if (x & 1)
            x ^= 1;
        ans = min(ans, sum1[x / 2] + sum2[x / 2] + abs(h[x] - v));
    }
    cout << ans << endl;
}