#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
vector<int> color;

void dfs(int v = 0, int cur = 0) {
    color[v] = cur;
    for (int u : edges[v]) {
        if (color[u] != -1) continue;
        dfs(u, 1 - cur);
    }
}

int main() {
    int n;
    cin >> n;
    edges.resize(n);
    color.assign(n, -1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs();

    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += color[i] == 0;

    int use = 0;
    if (cnt < n / 2) {
        use = 1;
    }

    cnt = 0;
    for (int i = 0; i < n and cnt < n / 2; i++) {
        if (color[i] == use) {
            cout << i + 1 << " ";
            cnt++;
        }
    }
    cout << endl;
}
