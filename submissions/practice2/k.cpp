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
using mint = modint998244353;
struct S {
    mint a;
    int size;
};
struct F {
    mint a, b;
};
S op(S l, S r) { return S{l.a + r.a, l.size + r.size}; }
S e() { return S{0, 0}; }
S mapping(F l, S r) { return S{r.a * l.a + r.size * l.b, r.size}; }
F composition(F l, F r) { return F{r.a * l.a, r.b * l.a + l.b}; }
F id() { return F{1, 0}; }
int main() {
    int n, q;
    cin >> n >> q;
    vector<S> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = {x, 1};
    }
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, b, c;
            cin >> l >> r >> b >> c;
            seg.apply(l, r, F{b, c});
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.prod(l, r).a.val() << endl;
        }
    }
}