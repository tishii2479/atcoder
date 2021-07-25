#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

using mint = atcoder::modint1000000007;
const int MAX_V = 210000;
const int INF = 1 << 25;

struct edge {
    int to;
    int cost;
};

typedef pair<int, int> P;  // first: 最短距離, second: 頂点番号

vector<vector<edge>> edges;
int V;
vector<int> d(MAX_V, INF);
vector<mint> cnt(MAX_V, INF);

void dijkstra(int s) {
    d[s] = 0;    // 始点sへの最短距離は0
    cnt[s] = 1;  // 始点sへの最短経路数は1

    priority_queue<P, vector<P>, greater<P>> que;  // 距離が小さい順に取り出せるようgreater<P>を指定
    que.push(P(0, s));
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;  // 更新した頂点の中で距離が最小の頂点v
        if (d[v] < p.first) {
            continue;
        }
        for (auto e : edges[v]) {  // 頂点vから出る辺eを走査
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
                cnt[e.to] = cnt[v];  // コストが更新された場合は直前の頂点への最短経路数で上書き
            } else if (d[e.to] == d[v] + e.cost) {
                cnt[e.to] += cnt[v];  // コストが一致する場合はこれまでの最短経路数を足し合わせ
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    edges.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back({b, 1});
        edges[b].push_back({a, 1});
    }

    dijkstra(0);

    if (cnt[n - 1].val() == INF) {
        cout << 0 << endl;
        return 0;
    }
    cout << cnt[n - 1].val() << endl;
}
