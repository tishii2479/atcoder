#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int h, w;
vector<vector<int>> dist(2100, vector<int>(2100, inf));
string field[2100];
vector<pint> teleporter[26];
vector<bool> used(26, false);
pint unit[4] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}};
void bfs(pint s) {
    dist[s.first][s.second] = 0;
    queue<pint> que;
    que.push(s);
    while (que.empty() == false) {
        auto p = que.front();
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
        int a = field[y][x] - 'a';
        if (a < 0 or a >= 26)
            continue;
        if (used[a])
            continue;
        used[a] = true;
        for (auto t : teleporter[a]) {
            int ny = t.first;
            int nx = t.second;
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
    pint s, g;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            char c = field[i][j];
            if (c == '.' or c == '#')
                continue;
            if (c == 'S') {
                s.first = i;
                s.second = j;
            } else if (c == 'G') {
                g.first = i;
                g.second = j;
            } else {
                int a = c - 'a';
                teleporter[a].push_back({i, j});
            }
        }
    bfs(s);
    // for (int i = 0; i < h; i++)
    // {
    //     for (int j = 0; j < w; j++)
    //         cout << dist[i][j] << " ";
    //     cout << endl;
    // }
    cout << (dist[g.first][g.second] == inf ? -1 : dist[g.first][g.second]) << endl;
}