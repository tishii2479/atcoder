#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
int op(int a, int b) { return a + b; }
int e() { return 0; }
int mapping(int f, int x) { return f + x; }
int composition(int f, int g) { return f + g; }
int id() { return 0; }
int main() {
    int n, q;
    cin >> n >> q;
    lazy_segtree<int, op, e, int, mapping, composition, id> seg(n);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        seg.apply(l, r + 1, 1);
    }
    for (int i = 0; i < n; i++)
        cout << seg.get(i) % 2;
    cout << endl;
}