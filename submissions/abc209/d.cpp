#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
vector<int> depth;

void dfs(int v, int p) {
    for (int u : edges[v]) {
        if (u == p) continue;
        depth[u] = depth[v] + 1;
        dfs(u, v);
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    edges.resize(n), depth.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    depth[0] = 0;
    dfs(0, -1);

    while (q--) {
        int c, d;
        cin >> c >> d;
        c--, d--;
        int val = depth[c] + depth[d];
        if (val % 2 == 0) {
            cout << "Town" << endl;
        } else {
            cout << "Road" << endl;
        }
    }
}
