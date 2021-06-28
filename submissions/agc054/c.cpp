#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

using S = int;
S op(S a, S b) { return a + b; }
S e() { return 0; }

int main() {
    using mint = modint998244353;
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    mint ans = 1;

    segtree<S, op, e> seg(n + 1);

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int val = seg.prod(p[i], n + 1);
        seg.set(p[i], 1);
        if (val == k) v.push_back(i);
    }

    for (int e : v) ans *= (n - e);

    cout << ans.val() << endl;
}
