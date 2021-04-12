#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
int main() {
    int n, m;
    cin >> n >> m;
    // year, town_a, town_b
    vector<pair<int, pair<int, int>>> road(m);
    for (int i = 0; i < m; i++) {
        int a, b, y;
        cin >> a >> b >> y;
        a--, b--;
        road[i] = {y, {a, b}};
    }
    int q;
    cin >> q;
    // year, town, idx
    vector<pair<int, pair<int, int>>> info(q);
    for (int i = 0; i < q; i++) {
        int v, w;
        cin >> v >> w;
        v--;
        info[i] = {w, {v, i}};
    }
    // answer
    vector<int> res(q);
    dsu uf(n);
    sort(road.rbegin(), road.rend());
    sort(info.rbegin(), info.rend());
    int cur = 210000;
    int j = 0;
    for (auto i : info) {
        int year = i.first, town = i.second.first, idx = i.second.second;
        while (road[j].first > year) {
            int a = road[j].second.first, b = road[j].second.second;
            uf.merge(a, b);
            j++;
        }
        res[idx] = uf.size(town);
    }
    for (int i = 0; i < q; i++) cout << res[i] << endl;
}