#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

    const int up = 101, down = 102;

    vector<pair<double, pair<int, int>>> edges;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dx = (v[i].first - v[j].first);
            double dy = (v[i].second - v[j].second);
            double dist = sqrt(dx * dx + dy * dy);
            edges.push_back({dist, {i, j}});
        }
    }

    for (int i = 0; i < n; i++) {
        double dx = 0, dy = v[i].second - 100;
        double dist = sqrt(dx * dx + dy * dy);
        edges.push_back({dist, {i, up}});
    }

    for (int i = 0; i < n; i++) {
        double dx = 0, dy = v[i].second + 100;
        double dist = sqrt(dx * dx + dy * dy);
        edges.push_back({dist, {i, down}});
    }

    edges.push_back({200, {up, down}});

    sort(edges.begin(), edges.end());

    atcoder::dsu uf(110);

    for (auto e : edges) {
        uf.merge(e.second.second, e.second.first);

        if (uf.same(up, down)) {
            printf("%.10lf\n", e.first / 2);
            return 0;
        }
    }
}
