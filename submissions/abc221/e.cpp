#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

using mint = atcoder::modint998244353;

struct S {
    mint value;
    int size;
};
using F = mint;

S op(S a, S b) { return {a.value + b.value, a.size + b.size}; }
S e() { return {0, 0}; }
S mapping(F f, S x) { return {f * x.value, x.size}; }
F composition(F f, F g) { return f * g; }
F id() { return 1; }

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<S> v(n, {0, 1});
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

    set<int> st;
    for (int i = 0; i < n; i++) st.insert(a[i]);
    int cur = 0;
    map<int, int> mp;
    for (int e : st) mp[e] = cur++;

    mint ans = 0;
    for (int i = 0; i < n; i++) {
        ans += seg.prod(0, mp[a[i]] + 1).value;
        seg.apply(0, n, 2);
        auto cur = seg.get(mp[a[i]]);
        seg.set(mp[a[i]], {cur.value + 1, cur.size});
    }

    cout << ans.val() << endl;
}
