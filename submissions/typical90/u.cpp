#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges, rev_edges;
vector<int> order, comp, t;
vector<bool> used;

void dfs(int v) {
    if (used[v]) return;
    used[v] = true;
    for (int u : rev_edges[v]) dfs(u);
    order.push_back(v);
}

void rdfs(int v, int ptr) {
    if (comp[v] != -1) return;
    comp[v] = ptr;
    for (int u : edges[v]) rdfs(u, ptr);
}

int main() {
    int n, m;
    cin >> n >> m;
    edges.resize(n), rev_edges.resize(n), used.assign(n, false), comp.assign(n, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        rev_edges[b].push_back(a);
    }

    for (int i = 0; i < n; i++) dfs(i);
    reverse(order.begin(), order.end());

    int ptr = 0;
    for (int i : order)
        if (comp[i] == -1) rdfs(i, ptr), ptr++;

    long long ans = 0;
    vector<int> cnt(ptr, 0);
    for (int i = 0; i < n; i++) cnt[comp[i]]++;
    for (int i = 0; i < ptr; i++) ans += (long long)cnt[i] * (cnt[i] - 1) / 2;

    cout << ans << endl;
}
