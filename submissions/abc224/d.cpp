#include <bits/stdc++.h>
using namespace std;

int main() {
    const int n = 9;
    int m;
    cin >> m;
    vector<vector<int>> edges(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<int> p(n, -1);
    for (int i = 0; i < n - 1; i++) {
        int pos;
        cin >> pos;
        p[pos - 1] = i;
    }

    set<vector<int>> seen;
    seen.insert(p);
    queue<pair<vector<int>, int>> q;
    q.push({p, 0});

    while (q.size()) {
        auto [vec, cnt] = q.front();
        q.pop();

        // check is ok
        bool ok = true;
        for (int i = 0; i < n - 1; i++) {
            if (vec[i] != i) ok = false;
        }

        if (ok) {
            cout << cnt << endl;
            return 0;
        }

        // search
        int open = -1;
        for (int i = 0; i < n; i++) {
            if (vec[i] == -1) open = i;
        }

        for (int u : edges[open]) {
            vector<int> copy = vec;
            swap(copy[u], copy[open]);
            if (seen.find(copy) != seen.end()) continue;
            seen.insert(copy);
            q.push({copy, cnt + 1});
        }
    }

    cout << -1 << endl;
}
