#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
int main() {
    int n, q;
    cin >> n >> q;
    fenwick_tree<int> tree(n + 1);
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    vector<pair<int, int>> query[n + 1];
    vector<int> ans(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        query[r].push_back({l, i});
    }
    vector<int> lastAppeared(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (lastAppeared[c[i]] > 0)
            tree.add(lastAppeared[c[i]], -1);
        tree.add(i, 1);
        lastAppeared[c[i]] = i;
        for (int j = 0; j < query[i].size(); j++)
            ans[query[i][j].second] = tree.sum(query[i][j].first, i);
    }
    for (int i = 0; i < q; i++)
        cout << ans[i] + 1 << endl;
}