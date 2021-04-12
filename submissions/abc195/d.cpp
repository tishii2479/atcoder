#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    ll n, m, q;
    cin >> n >> m >> q;
    vector<pll> vw(n);
    for (int i = 0; i < n; i++)
        cin >> vw[i].second >> vw[i].first;
    sort(vw.begin(), vw.end(), greater<pll>());
    vector<ll> x(m);
    for (int i = 0; i < m; i++)
        cin >> x[i];
    while (q--) {
        ll ans = 0;
        ll l, r;
        cin >> l >> r;
        l--, r--;
        vector<bool> used(m, false);
        for (int i = l; i <= r; i++)
            used[i] = true;
        for (int i = 0; i < n; i++) {
            ll v = vw[i].first;
            ll w = vw[i].second;
            int mnidx = -1;
            for (int j = 0; j < m; j++) {
                if (used[j])
                    continue;
                if (x[j] >= w) {
                    if (mnidx == -1 or x[j] < x[mnidx])
                        mnidx = j;
                }
            }
            if (mnidx != -1) {
                used[mnidx] = true;
                ans += v;
            }
        }
        cout << ans << endl;
    }
}