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
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<char>> field(h, vector<char>(w));
    vector<pint> pos(n + 1);
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            cin >> field[i][j];
            if (field[i][j] == 'X' or field[i][j] == '.')
                continue;
            if (field[i][j] == 'S')
                pos[0] = {j, i};
            else
                pos[field[i][j] - '0'] = {j, i};
        }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int sx = pos[i - 1].first;
        int sy = pos[i - 1].second;
        int gx = pos[i].first;
        int gy = pos[i].second;
        vector<vector<int>> dist(h, vector<int>(w, inf));
        dist[sy][sx] = 0;
        queue<pint> q;
        q.push({sx, sy});
        while (q.empty() == false) {
            auto p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            for (int i = 0; i < 4; i++) {
                int nx = x + unit[i].first;
                int ny = y + unit[i].second;
                if (nx < 0 or ny < 0 or nx >= w or ny >= h)
                    continue;
                if (field[ny][nx] == 'X')
                    continue;
                if (dist[ny][nx] <= dist[y][x] + 1)
                    continue;
                dist[ny][nx] = dist[y][x] + 1;
                q.push({nx, ny});
            }
        }
        ans += dist[gy][gx];
    }
    cout << ans << endl;
}