#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
int op(int l, int r) { return l + r; }
int e() { return 0; }
int t, x;
bool ok(int value) { return value < x; }
int main() {
    const int N = 210000;
    int q;
    cin >> q;
    segtree<int, op, e> seg(N);
    while (q--) {
        cin >> t >> x;
        if (t == 1) {
            int val = seg.get(x);
            seg.set(x, val + 1);
        } else {
            int val = seg.max_right(0, ok);
            cout << val << endl;
            int cnt = seg.get(val);
            seg.set(val, cnt - 1);
        }
    }
}