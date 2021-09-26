#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;

using S = int;
S op(S a, S b) { return max(a, b); }
S e() { return 0; }

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
    }

    atcoder::segtree<S, op, e> seg(n);
    for (int i = 0; i < n; i++)
        sort(edges[i].begin(), edges[i].end(), greater<int>());

    for (int i = 0; i < n; i++) {
        for (int u : edges[i]) {
            int val = seg.prod(0, u);
            int cur = seg.get(u);
            if (val + 1 > cur) seg.set(u, val + 1);
        }
    }

    int ans = seg.all_prod();
    cout << ans << endl;
}
