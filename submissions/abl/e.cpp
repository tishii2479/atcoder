#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
const int N = 210000;
mint ten[N], one[N];
struct S {
    int len;
    mint val;
};
using F = int;
S op(S l, S r) { return S{l.len + r.len, l.val * ten[r.len] + r.val}; }
S e() { return S{0, 0}; }
F id() { return 0; }
S mapping(F f, S s) {
    if (f == id()) return s;
    return S{s.len, one[s.len] * f};
}
F composition(F l, F r) { return (l == id() ? r : l); }
int main() {
    int n, q;
    cin >> n >> q;
    one[0] = 0, ten[0] = 1;
    for (int i = 1; i < N; i++) one[i] = one[i - 1] * 10 + 1;
    for (int i = 1; i < N; i++) ten[i] = ten[i - 1] * 10;
    vector<S> v(n, S{1, 1});
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
    for (int i = 0; i < q; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        seg.apply(l - 1, r, d);
        cout << seg.prod(0, n).val.val() << endl;
    }
}