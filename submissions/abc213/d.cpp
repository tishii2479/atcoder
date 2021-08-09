#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
vector<bool> seen;
vector<int> res;

void dfs(int cur, int par) {
    seen[cur] = true;
    res.push_back(cur);
    for (int u : edges[cur]) {
        if (u == par) continue;
        if (seen[u]) continue;
        dfs(u, cur);
        res.push_back(cur);
    }
}

int main() {
    int n;
    cin >> n;
    edges.resize(n);
    seen.assign(n, false);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    // sort
    for (int i = 0; i < n; i++) {
        sort(edges[i].begin(), edges[i].end());
    }

    dfs(0, -1);

    for (int r : res) cout << r + 1 << " ";
    cout << endl;
}
