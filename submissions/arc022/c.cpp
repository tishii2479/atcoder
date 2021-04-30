#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> edges;
vector<int> d;

void dfs(int v) {
    for (int u : edges[v]) {
        if (d[u] != -1) continue;
        d[u] = d[v] + 1;
        dfs(u);
    }
}

int main() {
    int n;
    cin >> n;
    edges.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    d.assign(n, -1);
    d[0] = 0;
    dfs(0);
    int v = max_element(d.begin(), d.end()) - d.begin();
    d.assign(n, -1);
    d[v] = 0;
    dfs(v);
    int u = max_element(d.begin(), d.end()) - d.begin();

    cout << v + 1 << " " << u + 1 << endl;
}
