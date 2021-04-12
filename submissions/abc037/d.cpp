#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = (1e9) + 7;
const int N = 1100;
ll cnt[N][N];
ll a[N][N];
bool seen[N][N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int h, w;
ll dfs(int y, int x) {
    if (seen[y][x]) return cnt[y][x];
    seen[y][x] = true;
    ll sum = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (nx < 0 or ny < 0 or nx >= w or ny >= h) continue;
        if (a[y][x] >= a[ny][nx]) continue;
        sum += dfs(ny, nx);
        sum %= MOD;
    }
    cnt[y][x] += sum;
    cnt[y][x] %= MOD;
    return cnt[y][x];
}
int main() {
    cin >> h >> w;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) cin >> a[i][j];
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (seen[i][j] == false) dfs(i, j);
    ll ans = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) ans = (ans + cnt[i][j]) % MOD;
    cout << ans << endl;
}