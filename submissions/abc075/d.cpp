#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 62;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n, k;
    cin >> n >> k;
    vector<pll> xi(n);
    vector<pll> xy(n);
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        xi[i] = {x, i};
        xy[i] = {x, y};
    }
    sort(xi.begin(), xi.end());
    ll ans = INF;
    for (int l = 0; l < n; l++) {
        for (int r = l + k - 1; r < n; r++) {
            vector<ll> ys;
            ll xrange = xi[r].first - xi[l].first;
            for (int i = l; i <= r; i++) {
                int ind = xi[i].second;
                ys.push_back(xy[ind].second);
            }
            sort(ys.begin(), ys.end());
            ll mn = INF;
            for (int i = 0; i + k - 1 < ys.size(); i++) {
                mn = min(mn, ys[i + k - 1] - ys[i]);
            }
            ans = min(mn * xrange, ans);
        }
    }
    cout << ans << endl;
}