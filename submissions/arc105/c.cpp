#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    const ll INF = 1LL << 60;
    int n, m;
    cin >> n >> m;
    vector<ll> w(n);
    vector<pair<ll, ll>> vl(m);
    for (int i = 0; i < n; i++) cin >> w[i];
    ll min_v = INF;
    for (int i = 0; i < m; i++) {
        cin >> vl[i].second >> vl[i].first;
        min_v = min(vl[i].first, min_v);
    }

    if (*max_element(w.begin(), w.end()) > min_v) {
        cout << -1 << endl;
        return 0;
    }

    sort(vl.begin(), vl.end());

    vector<ll> longest(m + 1, 0);
    ll cur = 0;
    for (int i = 0; i < m; i++) {
        cur = max(cur, vl[i].second);
        longest[i + 1] = cur;
    }

    vector<ll> v(m + 1, 0);
    for (int i = 0; i < m; i++) v[i + 1] = vl[i].first;

    sort(w.begin(), w.end());

    ll ans = INF;

    do {
        vector<ll> pos(n, 0);
        vector<ll> sums(n + 1);
        for (int i = 0; i < n; i++) sums[i + 1] = sums[i] + w[i];

        // for (int e : w) cout << e << " ";
        // cout << endl;
        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {
                ll total = sums[r + 1] - sums[l];
                int need = (lower_bound(v.begin(), v.end(), total) - v.begin()) - 1;
                assert(need >= 0);
                ll min_width = longest[need];
                // cout << l << " " << r << " " << total << " " << need << " " << min_width << endl;
                if (pos[r] - pos[l] < min_width) {
                    pos[r] = pos[l] + min_width;
                }
            }
        }

        // assert(false);
        ans = min(ans, pos[n - 1] - pos[0]);
        // for (int p : pos) cout << p << " ";
        // cout << endl;
    } while (next_permutation(w.begin(), w.end()));

    cout << ans << endl;
}
