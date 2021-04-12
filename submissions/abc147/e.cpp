#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
// x, y, able
bool dp[80][80][80 * 200];
int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    vector<vector<int>> b(h, vector<int>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> a[i][j];
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> b[i][j];
    vector<vector<int>> diff(h, vector<int>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            diff[i][j] = abs(a[i][j] - b[i][j]);
    dp[0][0][0] = true;
    for (int i = 1; i < 80 * 200; i++)
        dp[0][0][i] = false;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            if (i + 1 < h)
                for (int k = 0; k < 80 * 200; k++)
                    if (dp[i][j][k]) {
                        dp[i + 1][j][k + diff[i][j]] = true;
                        dp[i + 1][j][abs(k - diff[i][j])] = true;
                    }
            if (j + 1 < w)
                for (int k = 0; k < 80 * 200; k++)
                    if (dp[i][j][k]) {
                        dp[i][j + 1][k + diff[i][j]] = true;
                        dp[i][j + 1][abs(k - diff[i][j])] = true;
                    }
        }
    for (int i = 0; i < 80 * 200; i++) {
        if (dp[h - 1][w - 1][abs(i - diff[h - 1][w - 1])] or dp[h - 1][w - 1][i + diff[h - 1][w - 1]]) {
            cout << i << endl;
            return 0;
        }
    }
}