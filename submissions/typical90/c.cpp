#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> edges;
vector<int> depth;

void dfs(int v, int par = -1) {
    for (int u : edges[v]) {
        if (u == par) continue;
        depth[u] = depth[v] + 1;
        dfs(u, v);
    }
}

pair<int, pair<int, int>> find_diameter() {
    depth.assign(n, 0);
    depth[0] = 0;
    dfs(0);
    int furthest = max_element(depth.begin(), depth.end()) - depth.begin();
    depth.assign(n, 0);
    depth[furthest] = 0;
    dfs(furthest);
    int next_furthest = max_element(depth.begin(), depth.end()) - depth.begin();
    return make_pair(depth[next_furthest], make_pair(furthest, next_furthest));
}

int main() {
    cin >> n;
    edges.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    auto p = find_diameter();
    cout << p.first + 1 << endl;
}
