#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, long long>> edges(m);
    vector<vector<pair<int, long long>>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        long long s;
        cin >> u >> v >> s;
        v--, u--;
        edges[i] = {v, u, s};
        graph[v].push_back({u, s});
        graph[u].push_back({v, s});
    }

    vector<long long> value(n);
    vector<int> color;

    auto paint = [&](long long w) {
        color.assign(n, -1);
        value[0] = w;
        color[0] = 0;

        queue<int> q;
        q.push(0);

        while (q.size()) {
            int v = q.front();
            q.pop();
            for (auto e : graph[v]) {
                int u = e.first;
                if (color[u] != -1) continue;

                color[u] = 1 - color[v];
                value[u] = e.second - value[v];
                q.push(u);
            }
        }
    };

    paint(0);

    bool isBip = true, ok = true;
    for (auto e : edges) {
        if (color[get<0>(e)] == color[get<1>(e)]) isBip = false;
        if (value[get<0>(e)] + value[get<1>(e)] != get<2>(e)) ok = false;
    }

    if (isBip) {
        if (ok == false) {
            cout << 0 << endl;
        } else {
            long long l = 1LL << 60, r = 1LL << 60;
            for (int i = 0; i < n; i++) {
                if (color[i] == 0) {
                    l = min(l, value[i]);
                } else {
                    r = min(r, value[i]);
                }
            }
            cout << max(0LL, r + l - 1) << endl;
        }
    } else {
        long long w = 0;
        for (auto e : edges) {
            if (color[get<0>(e)] == color[get<1>(e)]) {
                w = abs(value[get<0>(e)] + value[get<1>(e)] - get<2>(e));
                break;
            }
        }

        paint(w / 2);
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (value[i] < 1) ok = false;
        }
        for (auto e : edges) {
            if (value[get<0>(e)] + value[get<1>(e)] != get<2>(e)) ok = false;
        }

        cout << ok << endl;
    }
}
