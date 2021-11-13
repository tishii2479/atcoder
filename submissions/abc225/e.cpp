#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using S = int;
S op(S a, S b) { return max(a, b); }
S e() { return 0; }

int main() {
    int n;
    cin >> n;
    using P = pair<long double, long double>;
    vector<P> v(n);
    set<long double> st;

    for (int i = 0; i < n; i++) {
        long double x, y;
        cin >> x >> y;

        v[i].first = atan2l(y, x - 1);
        v[i].second = atan2l(y - 1, x);
        st.insert(v[i].first);
        st.insert(v[i].second);
    }

    sort(v.begin(), v.end());

    map<long double, int> mp;
    int cur = 1;
    for (auto e : st) mp[e] = cur++;
    atcoder::segtree<S, op, e> seg(mp.size() + 100);

    for (auto [_l, _r] : v) {
        int l = mp[_l], r = mp[_r];
        swap(l, r);
        seg.set(r, max(seg.get(r), seg.prod(0, l + 1) + 1));
    }

    cout << seg.all_prod() << endl;
}
