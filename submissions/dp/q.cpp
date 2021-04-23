#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

using ll = long long;
using S = long long;
S op(S a, S b) { return max(a, b); }
S e() { return 0; }

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> a[i];

    set<ll> st;
    for (int i = 0; i < n; i++) st.insert(h[i]);
    st.insert(0);
    vector<ll> all_h;
    for (ll s : st) all_h.push_back(s);
    unordered_map<ll, int> mp;
    for (int i = 0; i < all_h.size(); i++) mp[all_h[i]] = i;
    segtree<S, op, e> seg(all_h.size());

    for (int i = 0; i < n; i++) {
        int idx = mp[h[i]];
        ll val = seg.get(idx);
        seg.set(idx, max(val, seg.prod(0, idx) + a[i]));
    }

    cout << seg.all_prod() << endl;
}
