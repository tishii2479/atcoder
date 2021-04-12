#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int h, w;
    cin >> h >> w;
    string field[110];
    vector<vector<int>> dp(h, vector<int>(w, inf));
    for (int i = 0; i < h; i++)
        cin >> field[i];
    dp[0][0] = (field[0][0] == '#');
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            if (i > 0)
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + (field[i][j] == '#' and field[i - 1][j] == '.'));
            if (j > 0)
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + (field[i][j] == '#' and field[i][j - 1] == '.'));
        }
    // for (int i = 0; i < h; i++)
    // {
    //     for (int j = 0; j < w; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    cout << dp[h - 1][w - 1] << endl;
}