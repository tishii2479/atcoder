#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using S = int;
S op(S a, S b) { return a ^ b; }
S e() { return 0; }
int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> res;
    for (int i = 0; i < n; i++) cin >> a[i];
    segtree<S, op, e> seg(a);
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            int val = seg.get(x - 1);
            seg.set(x - 1, val ^ y);
        } else {
            int val = seg.prod(x - 1, y);
            res.push_back(val);
        }
    }
    for (int r : res) cout << r << endl;
}