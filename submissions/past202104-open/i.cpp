#include <bits/stdc++.h>
using namespace std;

const int N = 110;
long long dp[N][N][N * 2];

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<long long>> a(h, vector<long long>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) cin >> a[i][j];

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int k = 0; k + 1 < N * 2; k++) {
                dp[i + 1][j + 1][k + 1] = max({
                    dp[i + 1][j + 1][k + 1],
                    dp[i][j + 1][k + 1],
                    dp[i + 1][j][k + 1],
                    dp[i][j + 1][k] + a[i][j],
                    dp[i + 1][j][k] + a[i][j],
                });
            }
        }
    }

    for (int i = 1; i <= h + w - 1; i++) {
        cout << dp[h][w][i] << endl;
    }
}
