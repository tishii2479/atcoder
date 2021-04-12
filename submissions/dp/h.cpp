#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define each(i, mp) for (auto &i : mp)
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repd(i, n) for (ll i = n - 1; i >= 0; i--)
#define MOD 1000000007
// #define MOD 998244353
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
ll dp[1100][1100];
char field[1100][1100];
int main() {
    int h, w;
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> field[i][j];
        }
    }
    dp[h][w] = 1;
    for (int y = h; y > 0; y--) {
        for (int x = w; x > 0; x--) {
            dp[y][x] += dp[y + 1][x] + dp[y][x + 1];
            dp[y][x] %= MOD;
            if (field[y][x] == '#')
                dp[y][x] = 0;
        }
    }
    cout << dp[1][1] << endl;
}