#include <bits/stdc++.h>
using namespace std;

const int N = 1100;
int dp[N * N * 4];
vector<pair<int, int>> edges[N * N * 4];

int idx(int x, int y, int dir) {
    return dir * N * N + y * N + x;
};

int main() {
    int h, w;
    cin >> h >> w;
    int sy, sx, ty, tx;
    cin >> sy >> sx >> ty >> tx;
    sy--, sx--, ty--, tx--;
    vector<string> field(h);

    for (int i = 0; i < h; i++) cin >> field[i];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < 4; k++) dp[idx(i, j, k)] = 1 << 30;

    using P = pair<int, int>;
    deque<int> q;

    pair<int, int> unit[4] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}};

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int k = 0; k < 4; k++) {
                int ny = i + unit[k].second, nx = j + unit[k].first;
                if (nx >= 0 and nx < w and ny >= 0 and ny < h and field[ny][nx] == '.') {
                    edges[idx(j, i, k)].push_back({idx(nx, ny, k), 0});
                }
                for (int l = 0; l < 4; l++) {
                    if (k != l)
                        edges[idx(j, i, k)].push_back({idx(j, i, l), 1});
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        dp[idx(sx, sy, i)] = 0;
        q.push_back(idx(sx, sy, i));
    }

    while (q.size()) {
        int i = q.front();
        q.pop_front();
        for (auto p : edges[i]) {
            int u = p.first, cost = p.second;
            if (dp[u] <= dp[i] + cost) continue;
            dp[u] = dp[i] + cost;
            if (cost == 1)
                q.push_back(u);
            else
                q.push_front(u);
        }
    }

    int ans = 1 << 30;
    for (int i = 0; i < 4; i++) ans = min(ans, dp[idx(tx, ty, i)]);
    cout << ans << endl;
}
