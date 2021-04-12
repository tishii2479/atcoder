#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
pint unit[4] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};
int main() {
    int h, w;
    cin >> h >> w;
    int sy, sx, gy, gx;
    cin >> sy >> sx >> gy >> gx;
    sy--, sx--, gy--, gx--;
    vector<string> field(h);
    for (int i = 0; i < h; i++)
        cin >> field[i];
    vector<vector<int>> dist(h, vector<int>(w, inf));
    queue<pint> q;
    q.push({sx, sy});
    dist[sy][sx] = 0;
    while (q.empty() == false) {
        pint p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + unit[i].first;
            int ny = y + unit[i].second;
            if (nx < 0 or ny < 0 or nx >= w or ny >= h)
                continue;
            if (field[ny][nx] == '#')
                continue;
            if (dist[ny][nx] <= dist[y][x] + 1)
                continue;
            dist[ny][nx] = min(dist[ny][nx], dist[y][x] + 1);
            q.push({nx, ny});
        }
    }
    cout << dist[gy][gx] << endl;
}