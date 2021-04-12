#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
const ll INF = 1LL << 60;
struct S {
    int l, r;
    ll cost;
};
ll op(ll a, ll b) {
    return min(a, b);
}
ll e() {
    return INF;
}
ll mapping(ll f, ll x) {
    return min(f, x);
}
ll composition(ll f, ll g) {
    return min(f, g);
}
ll id() {
    return INF;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<S> v(m);
    for (int i = 0; i < m; i++) {
        int l, r;
        ll c;
        cin >> l >> r >> c;
        l--, r--;
        v[i] = {l, r, c};
    }
    sort(v.begin(), v.end(), [&](S a, S b) {
        if (a.l != b.l)
            return a.l < b.l;
        else
            return a.cost <= b.cost;
    });
    lazy_segtree<ll, op, e, ll, mapping, composition, id> seg(n);
    int right = 0;
    seg.set(0, 0);
    for (int i = 0; i < m; i++) {
        int l = v[i].l, r = v[i].r;
        ll cost = v[i].cost;
        ll mn = seg.prod(l, r + 1);
        seg.apply(l, r + 1, cost + mn);
    }
    ll ans = seg.get(n - 1);
    cout << (ans >= INF ? -1 : ans) << endl;
}