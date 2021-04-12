#include <bits/stdc++.h>
using namespace std;
vector<int> sz, f;
vector<vector<int>> edge;
void dfs(int v) {
    int sum = 0;
    vector<int> cand;
    for (int u : edge[v]) {
        dfs(u);
        sz[v] += sz[u];
        if (sz[u] % 2) {
            cand.push_back(-f[u]);
        } else {
            if (f[u] < 0) {
                f[v] -= -f[u];
            } else {
                sum += -f[u];
            }
        }
    }
    sort(cand.begin(), cand.end(), greater<int>());
    cand.push_back(sum);
    for (int i = 0; i < cand.size(); i++) {
        if (i % 2) {
            f[v] += cand[i];
        } else {
            f[v] -= cand[i];
        }
    }
}
int main() {
    int n;
    cin >> n;
    edge.resize(n);
    sz.assign(n, 1), f.assign(n, 1);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        edge[p].push_back(i);
    }
    dfs(0);
    cout << (n + f[0]) / 2 << endl;
}