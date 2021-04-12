#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
ll field[3100][3100];
ll dp[3100][3100][5];
int main() {
    int h, w, k;
    cin >> h >> w >> k;
    for (int i = 0; i < k; i++) {
        ll r, c, v;
        cin >> r >> c >> v;
        r--, c--;
        field[r][c] = v;
    }
    dp[0][0][0] = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            for (int i = 0; i < 4; i++)
                if (y > 0)
                    dp[y][x][0] = max(dp[y][x][0], dp[y - 1][x][i]);
            for (int i = 3; i >= 0; i--) {
                if (x > 0)
                    dp[y][x][i] = max(dp[y][x][i], dp[y][x - 1][i]);
                if (field[y][x] > 0) {
                    dp[y][x][i + 1] = max(dp[y][x][i + 1], dp[y][x][i] + field[y][x]);
                }
            }
            // cout << dp[y][x][0] << ":";
            // cout << dp[y][x][1] << ":";
            // cout << dp[y][x][2] << ":";
            // cout << dp[y][x][3] << " ";
        }
        cout << endl;
    }
    ll ans = 0;
    for (int i = 0; i < 4; i++) {
        ans = max(ans, dp[h - 1][w - 1][i]);
    }
    cout << ans << endl;
}