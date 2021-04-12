#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int dist[51][51];
string field[51];
pint unit[4] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};
int h, w;
void bfs() {
    dist[0][0] = 0;
    queue<pint> que;
    que.push({0, 0});
    while (que.empty() == false) {
        pint p = que.front();
        que.pop();
        int y = p.first;
        int x = p.second;
        for (int i = 0; i < 4; i++) {
            int ny = y + unit[i].first;
            int nx = x + unit[i].second;
            if (ny < 0 or nx < 0 or ny >= h or nx >= w)
                continue;
            if (field[ny][nx] == '#')
                continue;
            if (dist[ny][nx] > dist[y][x] + 1) {
                dist[ny][nx] = dist[y][x] + 1;
                que.push({ny, nx});
            }
        }
    }
}
int main() {
    cin >> h >> w;
    for (int i = 0; i < h; i++)
        cin >> field[i];
    int max = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (field[i][j] == '.')
                max++;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            dist[i][j] = inf;
    bfs();
    // for (int i = 0; i < h; i++)
    // {
    //     for (int j = 0; j < w; j++)
    //         cout << dist[i][j] << " ";
    //     cout << endl;
    // }
    if (dist[h - 1][w - 1] == inf)
        cout << -1 << endl;
    else
        cout << max - dist[h - 1][w - 1] - 1 << endl;
}