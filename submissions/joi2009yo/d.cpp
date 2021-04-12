#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int m, n;
vector<vector<int>> field(91, vector<int>(91));
int ux[4] = {1, 0, -1, 0};
int uy[4] = {0, -1, 0, 1};
int dfs(int x, int y, vector<vector<bool>> used, int cnt) {
    int res = cnt;
    for (int i = 0; i < 4; i++) {
        int nx = x + ux[i];
        int ny = y + uy[i];
        if (nx < 0 or ny < 0 or nx >= m or ny >= n)
            continue;
        if (field[ny][nx] == 0 or used[ny][nx])
            continue;
        used[ny][nx] = true;
        res = max(res, dfs(nx, ny, used, cnt + 1));
        used[ny][nx] = false;
    }
    return res;
}
int solve(int sx, int sy) {
    vector<vector<bool>> used(n, vector<bool>(m, false));
    used[sy][sx] = true;
    return dfs(sx, sy, used, 1);
}
int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> field[i][j];
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (field[i][j] == 1)
                ans = max(ans, solve(j, i));
    cout << ans << endl;
}