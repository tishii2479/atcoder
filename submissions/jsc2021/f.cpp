#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using S = ll;
S op(S a, S b) { return a + b; }
S e() { return 0; }
int main() {
    ll n, m, q;
    cin >> n >> m >> q;
    vector<ll> a(n, 0), b(m, 0);
    vector<pair<ll, pair<ll, ll>>> query(q);
    set<ll> st;
    for (ll i = 0; i < q; i++) {
        ll t, x, y;
        cin >> t >> x >> y;
        x--;
        query[i] = {t, {x, y}};
        st.insert(y);
    }
    st.insert(0);
    unordered_map<ll, ll> mp;
    vector<ll> ys;
    for (ll s : st) ys.push_back(s);
    for (ll i = 0; i < ys.size(); i++) {
        mp[ys[i]] = i;
    }
    segtree<S, op, e> segA(ys.size()), segB(ys.size()), segA_cnt(ys.size()), segB_cnt(ys.size());
    segA_cnt.set(0, n);
    segB_cnt.set(0, m);
    ll ans = 0;
    for (ll i = 0; i < q; i++) {
        ll t = query[i].first, x = query[i].second.first, y = query[i].second.second;
        if (t == 1) {
            bool flag = false;
            ll cur = a[x];
            ll l = mp[cur];
            ll r = mp[y];
            if (l > r) {
                swap(l, r);
                flag = true;
            }
            // cout << l << " " << r << endl;
            ll cnt = segB_cnt.prod(l, r);
            if (flag) {
                // ans -= y * cnt - segB.prod(l, r);
                ans += segB_cnt.prod(0, l) * (y - cur);
                ans += segB.prod(l, r) - cnt * cur;
            } else {
                ans += y * cnt - segB.prod(l, r);
                ans += segB_cnt.prod(0, l) * (y - cur);
            }
            if (flag) swap(l, r);
            segA_cnt.set(l, segA_cnt.get(l) - 1);
            segA_cnt.set(r, segA_cnt.get(r) + 1);
            segA.set(l, segA_cnt.get(l) * ys[l]);
            segA.set(r, segA_cnt.get(r) * ys[r]);
            a[x] = y;
        } else {
            bool flag = false;
            ll cur = b[x];
            ll l = mp[cur];
            ll r = mp[y];
            if (l > r) {
                swap(l, r);
                flag = true;
            }
            // cout << l << " " << r << endl;
            ll cnt = segA_cnt.prod(l, r);
            if (flag) {
                // ans -= y * cnt - segA.prod(l, r);
                ans += segA.prod(l, r) - cnt * cur;
                ans += segA_cnt.prod(0, l) * (y - cur);
            } else {
                ans += y * cnt - segA.prod(l, r);
                ans += segA_cnt.prod(0, l) * (y - cur);
            }
            if (flag) swap(l, r);
            segB_cnt.set(l, segB_cnt.get(l) - 1);
            segB_cnt.set(r, segB_cnt.get(r) + 1);
            segB.set(l, segB_cnt.get(l) * ys[l]);
            segB.set(r, segB_cnt.get(r) * ys[r]);
            b[x] = y;
        }
        // cout << i << endl;
        // for (int i = 0; i < q; i++) {
        //     cout << ys[i] << " " << segA.get(i) << " " << segA_cnt.get(i) << endl;
        // }
        // for (int i = 0; i < q; i++) {
        //     cout << ys[i] << " " << segB.get(i) << " " << segB_cnt.get(i) << endl;
        // }
        cout << ans << endl;
    }
}