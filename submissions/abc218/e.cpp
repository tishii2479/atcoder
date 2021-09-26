#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    atcoder::dsu uf(n);
    vector<pair<int, pair<int, int>>> edges;
    long long sum = 0;
    int cnt = 1;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        if (c > 0) {
            sum += c;
            edges.push_back({c, {a, b}});
        } else {
            if (!uf.same(a, b)) {
                cnt++;
                uf.merge(a, b);
            }
        }
    }

    sort(edges.begin(), edges.end());

    for (int i = 0; i < edges.size() and cnt < n; i++) {
        int u = edges[i].second.first, v = edges[i].second.second;
        long long c = edges[i].first;
        if (uf.same(u, v)) continue;
        cnt++;
        sum -= c;
        uf.merge(u, v);
    }
    cout << sum << endl;
}
