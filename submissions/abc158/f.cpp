#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

using S = int;
S op(S a, S b) { return max(a, b); }
S e() { return 0; }

int main() {
    const int inf = 1 << 30;
    using mint = modint998244353;
    int n;
    cin >> n;
    vector<pair<int, int>> xd(n);
    for (int i = 0; i < n; i++) cin >> xd[i].first >> xd[i].second;

    sort(xd.begin(), xd.end());

    vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = i;
    segtree<S, op, e> seg(v);

    for (int i = n - 1; i >= 0; i--) {
        int l = i - 1, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (xd[m].first < xd[i].first + xd[i].second)
                l = m;
            else
                r = m;
        }
        int val = seg.prod(i, r);
        // cout << i << " " << val << " " << r << endl;
        seg.set(i, val);
    }

    vector<mint> dp(n + 1, 0);
    dp[n] = 1;

    // x bigger
    for (int i = n - 1; i >= 0; i--) {
        // not use
        dp[i] += dp[i + 1];

        // use
        int cur = seg.get(i);

        // cout << dp[i].val() << " " << i << " " << cur << " " << g_cnt << " " << g[0] << endl;
        dp[i] += dp[cur + 1];
    }

    // for (auto e : dp) cout << e.val() << " ";
    // cout << endl;

    cout << dp[0].val() << endl;
}
