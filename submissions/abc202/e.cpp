#include <bits/stdc++.h>
using namespace std;

const int N = 210000;

// 各クエリの結果
vector<int> res(N);
// クエリの情報
// first := クエリ番号
// second := クエリのDiの値
vector<vector<pair<int, int>>> id(N);
// 辺
vector<vector<int>> edges(N);
// 各頂点の深さ
vector<int> depth(N, 0);
// 探索時に更新する深さをカウントする配列
vector<int> cur(N, 0);

// 根からの探索
void dfs(int v = 0, int par = -1) {
    // 各クエリについて、訪問時にcur[Di]の値を引いておく
    for (int i = 0; i < id[v].size(); i++) {
        int idx = id[v][i].first, d = id[v][i].second;
        res[idx] -= cur[d];
    }

    // curの中身を更新する
    cur[depth[v]]++;

    // 子供への探索
    for (int u : edges[v]) {
        if (u == par) continue;
        depth[u] = depth[v] + 1;
        dfs(u, v);
    }

    // 各クエリについて、探索終了時にcur[Di]の値を足す
    for (int i = 0; i < id[v].size(); i++) {
        int idx = id[v][i].first, d = id[v][i].second;
        res[idx] += cur[d];
    }
}

int main() {
    // 入力受け取り
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        edges[p].push_back(i);
        edges[i].push_back(p);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int u, d;
        cin >> u >> d;
        u--;
        id[u].push_back({i, d});
    }

    // 探索
    dfs();

    // 答えの出力
    for (int i = 0; i < q; i++) cout << res[i] << endl;
}
