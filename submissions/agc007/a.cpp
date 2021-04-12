#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
bool dp[10][10];
int main() {
    int h, w;
    cin >> h >> w;
    string field[h];
    int cnt = 0;
    for (int i = 0; i < h; i++) {
        cin >> field[i];
    }
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            if (field[y][x] == '#')
                cnt++;
    if (cnt != h + w - 1) {
        cout << "Impossible" << endl;
        return 0;
    }
    dp[0][0] = true;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i > 0 and field[i - 1][j] == '#')
                dp[i][j] = dp[i - 1][j] or dp[i][j];
            if (j > 0 and field[i][j - 1] == '#')
                dp[i][j] = dp[i][j] or dp[i][j - 1];
        }
    }
    cout << (dp[h - 1][w - 1] ? "Possible" : "Impossible") << endl;
}