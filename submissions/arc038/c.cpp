#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

using S = int;
const S inf = 1 << 30;
S op(S a, S b) { return min(a, b); }
S e() { return inf; }
int t;
S f(S val) { return val >= t; }

int main() {
    int n;
    cin >> n;
    vector<int> c(n), a(n);
    for (int i = 1; i < n; i++) cin >> c[i] >> a[i];

    segtree<S, op, e> seg(n + 10);
    vector<int> g(n);
    seg.set(0, 0);
    for (int i = 1; i < n + 10; i++) seg.set(i, -1);

    for (int i = 1; i < n; i++) {
        t = i - c[i];
        int val = seg.max_right(0, f);
        g[i] = val;
        // cout << t << " " << i << " " << g[i] << endl;
        seg.set(val, i);
    }

    int cum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) continue;
        cum ^= g[i];
    }
    if (cum == 0)
        cout << "Second" << endl;
    else
        cout << "First" << endl;
}
