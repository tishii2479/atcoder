#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    const int inf = 1 << 30;
    int h, w, k;
    cin >> h >> w >> k;
    int x1, x2, y1, y2;
    cin >> y1 >> x1 >> y2 >> x2;
    x1--, y1--, x2--, y2--;
    vector<vector<char>> c(h, vector<char>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> c[i][j];
    vector<vector<int>> dist(h, vector<int>(w, inf));
    dist[y1][x1] = 0;
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {x1, y1}});
    pair<int, int> unit[4] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
    };
    while (q.empty() == false) {
        auto p = q.front();
        q.pop();
        int y = p.second.second, x = p.second.first;
        int d = p.first;
        if (dist[y][x] < d)
            continue;
        for (int i = 0; i < 4; i++)
            for (int d = 1; d <= k; d++) {
                int nx = x + unit[i].first * d, ny = y + unit[i].second * d;
                if (nx < 0 or nx >= w or ny < 0 or ny >= h)
                    break;
                if (c[ny][nx] == '@')
                    break;
                if (dist[ny][nx] <= dist[y][x])
                    break;
                if (dist[ny][nx] == inf) {
                    dist[ny][nx] = dist[y][x] + 1;
                    q.push({dist[ny][nx], {nx, ny}});
                }
            }
    }
    cout << (dist[y2][x2] == inf ? -1 : dist[y2][x2]) << endl;
}