#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, int>>> edges(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    set<int> visited;
    visited.insert(0);

    set<pair<int, int>> cand;

    for (auto p : edges[0]) {
        cand.insert({p.second, p.first});
    }

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        set<int> new_visit;
        vector<pair<int, int>> del;
        for (auto p : cand) {
            if (p.first > x) break;
            del.push_back(p);
            new_visit.insert(p.second);
        }

        for (auto p : del) cand.erase(p);

        for (int v : new_visit) {
            for (auto p : edges[v]) {
                if (visited.find(p.first) == visited.end()) {
                    cand.insert({p.second, p.first});
                }
            }
            visited.insert(v);
        }

        cout << visited.size() << endl;
    }
}
