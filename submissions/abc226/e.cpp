#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

using mint = atcoder::modint998244353;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;

    atcoder::dsu uf(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges.push_back({u, v});
        uf.merge(u, v);
    }

    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        if (uf.size(i) == 1) {
            cout << 0 << endl;
            return 0;
        }
    }

    for (auto [u, v] : edges) {
        mp[uf.leader(u)]++;
    }

    int cnt = 0;
    for (auto [leader, edge_cnt] : mp) {
        cnt++;
        if (uf.size(leader) != edge_cnt) {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << mint(2).pow(cnt).val() << endl;
}
