#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;

using ll = long long;
using P = pair<int, ll>;

int main() {
    int n;
    cin >> n;
    atcoder::dsu uf(n);
    vector<pair<ll, pair<int, int>>> edges(n - 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--, v--;
        edges[i] = {w, {u, v}};
    }

    sort(edges.begin(), edges.end());

    ll ans = 0;

    for (auto p : edges) {
        ans += (long long)uf.size(p.second.first) * uf.size(p.second.second) * p.first;
        uf.merge(p.second.first, p.second.second);
    }

    cout << ans << endl;
}
