#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
pint unit[4] = {
    {1, 0},
    {0, 1},
    {0, -1},
    {-1, 0}};
int h, w;
string field[410];
vector<vector<bool>> seen(410, vector<bool>(410, false));
void bfs(int x, int y, ll &bcnt, ll &wcnt) {
    if (seen[y][x])
        return;
    seen[y][x] = true;
    // cout << "x, y: " << x << " " << y << " " << field[y][x] << endl;
    if (field[y][x] == '0')
        wcnt++;
    else
        bcnt++;
    for (int i = 0; i < 4; i++) {
        int nx = x + unit[i].first;
        int ny = y + unit[i].second;
        if (nx < 0 or nx >= w or ny < 0 or ny >= h)
            continue;
        if (field[ny][nx] == field[y][x])
            continue;
        bfs(nx, ny, wcnt, bcnt);
    }
}
int main() {
    cin >> h >> w;
    vector<pint> st;
    for (int i = 0; i < h; i++) {
        cin >> field[i];
    }
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (field[y][x] == '#')
                st.push_back({x, y});
        }
    }
    ll ans = 0;
    for (pint p : st) {
        ll bcnt = 0;
        ll wcnt = 0;
        bfs(p.first, p.second, bcnt, wcnt);
        ans += bcnt * wcnt;
        // cout << bcnt << " " << wcnt << endl;
    }
    cout << ans << endl;
}