#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> t;
vector<bool> seen;
vector<vector<int>> edges;
ll res = 0;

void dfs(int v) {
    seen[v] = true;
    t.push_back(v);
    for (int u : edges[v]) {
        if (seen[u]) continue;
        dfs(u);
    }
}

void dfs2(int cur = 0, vector<int> color = vector<int>(20, -1)) {
    if (cur == t.size()) {
        res++;
        return;
    }
    int v = t[cur];

    vector<int> ok(3, true);
    for (int u : edges[v]) {
        if (color[u] != -1) ok[color[u]] = false;
    }

    for (int i = 0; i < 3; i++) {
        if (ok[i]) {
            color[v] = i;
            dfs2(cur + 1, color);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    edges.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    seen.assign(n, false);
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        if (seen[i]) continue;
        t.clear();
        dfs(i);
        dfs2();
        ans *= res;
        res = 0;
    }
    cout << ans << endl;
}
