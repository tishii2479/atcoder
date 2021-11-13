#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    vector<int> cnt(n, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        cnt[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        if (cnt[i] == 0) pq.push(i);
    }

    vector<int> res;

    while (pq.size()) {
        int v = pq.top();
        pq.pop();
        res.push_back(v);
        for (int u : edges[v]) {
            cnt[u]--;
            if (cnt[u] == 0) pq.push(u);
        }
    }
    if (res.size() != n) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) cout << res[i] + 1 << " ";
    cout << endl;
}
