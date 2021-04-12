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
ll op(ll a, ll b) { return max(a, b); }
ll e() { return -INF; }
int main() {
    ll n, d;
    cin >> n >> d;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    int k1 = n / 2, k2 = n - k1;
    // 市場価値 a - b, 貴重度 b - a
    vector<pll> res1(pow(3LL, k1));
    for (int bit = 0; bit < pow(3LL, k1); bit++) {
        ll s1 = 0, s2 = 0;
        int tmp = bit;
        for (int i = 0; i < k1; i++) {
            int t = tmp % 3;
            if (t == 0) {
                s1 += x[i];
                s2 -= y[i];
            } else if (t == 1) {
                s1 -= x[i];
                s2 += y[i];
            }
            tmp /= 3;
        }
        res1[bit] = {s1, s2};
    }
    // 市場価値 a - b, 貴重度 b - a
    vector<pll> res2(pow(3LL, k2));
    for (int bit = 0; bit < pow(3LL, k2); bit++) {
        ll s1 = 0, s2 = 0;
        int tmp = bit;
        for (int i = 0; i < k2; i++) {
            int t = tmp % 3;
            if (t == 0) {
                s1 += x[i + k1];
                s2 -= y[i + k1];
            } else if (t == 1) {
                s1 -= x[i + k1];
                s2 += y[i + k1];
            }
            tmp /= 3;
        }
        res2[bit] = {s1, s2};
    }
    sort(res2.begin(), res2.end());
    vector<ll> vec1(pow(3LL, k2)), vec2(pow(3LL, k2));
    for (int i = 0; i < pow(3LL, k2); i++)
        vec1[i] = res2[i].first, vec2[i] = res2[i].second;
    segtree<ll, op, e> seg(vec2);
    ll ans = -INF;
    for (int i = 0; i < pow(3LL, k1); i++) {
        ll diff = res1[i].first;
        ll cur = res1[i].second;
        int l = lower_bound(vec1.begin(), vec1.end(), -d - diff) - vec1.begin();
        int r = upper_bound(vec1.begin(), vec1.end(), d - diff) - vec1.begin();
        if (l > r)
            continue;
        ll mx = seg.prod(l, r);
        // cout << diff << " " << cur << " " << l << " " << r << " " << mx << endl;
        ans = max(mx + cur, ans);
    }
    cout << ans << endl;
}