#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
ll op(ll a, ll b) { return min(a, b); }
ll e() { return INF; }
int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    segtree<ll, op, e> seg(a);
    ll ans = INF;
    for (int i = 0; i < n; i++) {
        ll sum = i * x;
        for (int j = 0; j < n; j++) {
            ll val = seg.prod(max(0, j - i), j + 1);
            if (j - i < 0)
                val = min(seg.prod((j - i + n) % n, n), val);
            sum += val;
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
}