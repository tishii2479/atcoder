#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

int h, w, q;

int main() {
    cin >> h >> w >> q;

    auto idx = [](int r, int c) -> int {
        return r * w + c;
    };

    vector<vector<bool>> field(h, vector<bool>(w, false));
    dsu uf(h * w);

    pair<int, int> unit[4] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
    };

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int r, c;
            cin >> r >> c;
            r--, c--;
            field[r][c] = true;
            for (int i = 0; i < 4; i++) {
                int nr = r + unit[i].first, nc = c + unit[i].second;
                if (nr < 0 or nc < 0 or nr >= h or nc >= w) continue;
                if (field[nr][nc]) uf.merge(idx(r, c), idx(nr, nc));
            }
        } else {
            int ra, rb, ca, cb;
            cin >> ra >> ca >> rb >> cb;
            ra--, ca--, rb--, cb--;
            if (ra == rb and ca == cb) {
                cout << (field[ra][ca] ? "Yes" : "No") << endl;
                continue;
            }
            cout << (uf.same(idx(ra, ca), idx(rb, cb)) ? "Yes" : "No") << endl;
        }
    }
}
