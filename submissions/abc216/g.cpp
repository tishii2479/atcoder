#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

using S = int;
S op(S a, S b) { return a + b; }
S e() { return 0; }

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> v(n);
    for (int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--;
        v[r].push_back({l, x});
    }

    atcoder::segtree<S, op, e> seg(n);

    for (int r = 0; r < n; r++) {
        for (auto p : v[r]) {
            int l = p.first, x = p.second;
            int sum = seg.prod(l, r + 1);
            if (sum >= x) continue;

            int need = x - sum;
            int j = r;

            while (need > 0) {
                if (seg.get(j) == 0) {
                    need--;
                    seg.set(j, 1);
                }
                j--;
            }
        }
    }

    for (int i = 0; i < n; i++) cout << seg.get(i) << " ";
    cout << endl;
}
