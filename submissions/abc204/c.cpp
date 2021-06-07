#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans = 0;
vector<vector<int>> edges;
vector<bool> seen;

void dfs(int v) {
    for (int u : edges[v]) {
        if (seen[u]) continue;
        seen[u] = true;
        ans++;
        dfs(u);
    }
}

void solve(int s) {
    seen.assign(n, false);
    seen[s] = true;
    ans++;
    dfs(s);
}

int main() {
    cin >> n >> m;
    edges.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
    }

    for (int i = 0; i < n; i++) solve(i);

    cout << ans << endl;
}
