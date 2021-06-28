#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

int idx() {
    static int id = -1;
    return ++id;
}

int main() {
    const int N = 1100;
    int h, w, n;
    cin >> h >> w >> n;

    const int src = idx(), dst = idx();
    vector<int> row(h), col(w);
    for (int i = 0; i < h; i++) row[i] = idx();
    for (int i = 0; i < w; i++) col[i] = idx();

    vector<int> token_r(n), token_c(n);
    for (int i = 0; i < n; i++) token_r[i] = idx(), token_c[i] = idx();

    mf_graph<int> graph(idx());

    for (int i = 0; i < h; i++) graph.add_edge(src, row[i], 1);
    for (int i = 0; i < w; i++) graph.add_edge(col[i], dst, 1);

    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        for (int j = a; j <= c; j++) graph.add_edge(row[j], token_r[i], 1);
        graph.add_edge(token_r[i], token_c[i], 1);
        for (int j = b; j <= d; j++) graph.add_edge(token_c[i], col[j], 1);
    }

    cout << graph.flow(src, dst) << endl;
}
