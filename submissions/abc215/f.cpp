#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;

using S = int;
S op_max(S a, S b) { return max(a, b); }
S e_max() { return -1; }
S op_min(S a, S b) { return min(a, b); }
S e_min() { return 1 << 30; }

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    vector<pair<int, int>> p(n);

    for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;

    sort(p.begin(), p.end());

    for (int i = 0; i < n; i++) mp[p[i].first] = i;

    atcoder::segtree<S, op_max, e_max> seg_max(n);
    atcoder::segtree<S, op_min, e_min> seg_min(n);

    for (int i = 0; i < n; i++) {
        seg_max.set(i, p[i].second);
        seg_min.set(i, p[i].second);
    }

    vector<int> x(n);
    for (int i = 0; i < n; i++) x[i] = p[i].first;

    int l = 0, r = 1 << 30;

    while (r - l > 1) {
        int m = (l + r) / 2;
        bool ok = false;

        for (int i = 0; i < n; i++) {
            int left = lower_bound(x.begin(), x.end(), p[i].first + m) - x.begin();
            if (seg_max.prod(left, n) >= p[i].second + m) ok = true;
            if (seg_min.prod(left, n) <= p[i].second - m) ok = true;
        }

        if (ok) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << l << endl;
}
