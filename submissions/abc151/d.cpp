#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
#define each(i, mp) for (auto &i : mp)
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
const ll INF = 1LL << 60;
const int inf = 1 << 29;
const int MOD = 1000000007;
// const int MOD = 998244353;
char field[22][22];
int h, w;
pint unit[4] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
};
bool infield(int x, int y) {
    if (x >= w or x < 0)
        return false;
    if (y >= h or y < 0)
        return false;
    return true;
}
int sol(int x, int y) {
    if (field[y][x] == '#')
        return 0;
    queue<pint> queue;
    queue.push({x, y});
    vector<vector<int>> dist(22, vector<int>(22, inf));
    vector<vector<int>> found(22, vector<int>(22, false));
    dist[y][x] = 0;
    int max = 0;
    while (queue.empty() == false) {
        auto p = queue.front();
        queue.pop();
        for (int i = 0; i < 4; i++) {
            int nx = p.first + unit[i].first;
            int ny = p.second + unit[i].second;
            if (infield(nx, ny) and field[ny][nx] == '.' and dist[ny][nx] == inf) {
                dist[ny][nx] = dist[p.second][p.first] + 1;
                queue.push({nx, ny});
                chmax(max, dist[ny][nx]);
            }
        }
    }
    // for (int i = 0; i < h; i++)
    // {
    //     for (int j = 0; j < w; j++)
    //     {
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return max;
}
int solve() {
    int ans = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            chmax(ans, sol(x, y));
        }
    }
    return ans;
}
int main() {
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> field[i][j];
        }
    }
    cout << solve() << endl;
}