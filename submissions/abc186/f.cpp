#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
int main() {
    int h, w, m;
    cin >> h >> w >> m;
    vector<vector<int>> yoko(h, vector<int>({w})), tate(w, vector<int>({h}));
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        yoko[x].push_back(y);
        tate[y].push_back(x);
    }
    for (int i = 0; i < h; i++)
        sort(yoko[i].begin(), yoko[i].end());
    for (int i = 0; i < w; i++)
        sort(tate[i].begin(), tate[i].end());
    long long res = 0;
    for (int i = 0; i < yoko[0][0]; i++)
        res += tate[i][0];
    fenwick_tree<int> tree(w + 1);
    for (int j = yoko[0][0]; j < w; j++)
        tree.add(j, 1);
    for (int i = 0; i < tate[0][0]; i++) {
        res += tree.sum(0, yoko[i][0]);
        for (int y : yoko[i])
            if (tree.sum(y, y + 1) == 0)
                tree.add(y, 1);
    }
    cout << res << endl;
}