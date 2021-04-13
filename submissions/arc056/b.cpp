#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
int main() {
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    vector<vector<int>> edges(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dsu uf(n);
    vector<int> res;
    vector<bool> used(n, false);
    for (int i = n - 1; i >= 0; i--) {
        if (uf.same(i, s)) {
            res.push_back(i + 1);
            stack<int> st;
            st.push(i);
            while (st.size()) {
                int v = st.top();
                st.pop();
                if (used[v]) continue;
                if (v < i) continue;
                used[v] = true;
                for (int u : edges[v]) {
                    uf.merge(v, u);
                    if (used[u] == false) {
                        st.push(u);
                    }
                }
            }
        }
    }
    reverse(res.begin(), res.end());
    for (int r : res) cout << r << endl;
}