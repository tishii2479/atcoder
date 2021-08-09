#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) cin >> s[i];

    const int inf = 1 << 30;

    vector<vector<int>> dist(h, vector<int>(w, inf));
    using P = pair<int, pair<int, int>>;
    priority_queue<P, vector<P>, greater<P>> q;
    q.push({0, {0, 0}});
    dist[0][0] = 0;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    int dx8[8] = {0, 1, 0, -1, 1, 1, -1, -1};
    int dy8[8] = {1, 0, -1, 0, 1, -1, 1, -1};

    while (q.size()) {
        auto p = q.top();
        int x = p.second.first, y = p.second.second, d = p.first;
        q.pop();
        if (dist[y][x] < d) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 or ny < 0 or nx >= w or ny >= h) continue;

            int cost = (s[ny][nx] == '#');
            if (dist[ny][nx] <= dist[y][x]) continue;

            dist[ny][nx] = dist[y][x] + cost;
            q.push({dist[ny][nx], {nx, ny}});

            if (cost == 1) {
                // cout << ny << " " << nx << " " << dist[ny][nx] << endl;
                for (int i = 0; i < 8; i++) {
                    int nx2 = nx + dx8[i], ny2 = ny + dy8[i];
                    if (nx2 < 0 or ny2 < 0 or nx2 >= w or ny2 >= h) continue;
                    if (dist[ny2][nx2] <= dist[ny][nx] + 1) continue;
                    dist[ny2][nx2] = dist[ny][nx];
                    q.push({dist[ny2][nx2], {nx2, ny2}});
                }
            }
        }
    }

    // for (int i = 0; i < h; i++) {
    //     for (int j = 0; j < w; j++) cout << dist[i][j] << " ";
    //     cout << endl;
    // }

    cout << dist[h - 1][w - 1] << endl;
}
