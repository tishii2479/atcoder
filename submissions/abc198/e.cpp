#include <bits/stdc++.h>
using namespace std;
const int N = 210000;
vector<bool> ok(N, true);
vector<vector<int>> edges(N);
vector<int> cur(N, 0);
vector<int> c(N);
void dfs(int v, int p = -1) {
    if (cur[c[v]] > 0) ok[v] = false;
    cur[c[v]]++;
    for (int u : edges[v]) {
        if (u == p) continue;
        dfs(u, v);
    }
    cur[c[v]]--;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(0);
    for (int i = 0; i < n; i++) {
        if (ok[i]) cout << i + 1 << endl;
    }
}