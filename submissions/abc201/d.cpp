#include <bits/stdc++.h>
using namespace std;

int dp[2100][2100];

int effect(char c) {
    if (c == '+') return 1;
    return -1;
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) cin >> a[i][j];

    dp[h - 1][w - 1] = 0;
    for (int i = h - 1; i >= 0; i--) {
        for (int j = w - 1; j >= 0; j--) {
            if ((i + j) % 2 == 0) {
                // Takahashi
                if (j < w - 1 and i < h - 1) {
                    dp[i][j] = max(dp[i][j + 1] + effect(a[i][j + 1]),
                                   dp[i + 1][j] + effect(a[i + 1][j]));
                } else if (j < w - 1) {
                    dp[i][j] = dp[i][j + 1] + effect(a[i][j + 1]);
                } else if (i < h - 1) {
                    dp[i][j] = dp[i + 1][j] + effect(a[i + 1][j]);
                }
            } else {
                // Aoki
                if (j < w - 1 and i < h - 1) {
                    dp[i][j] = min(dp[i][j + 1] - effect(a[i][j + 1]),
                                   dp[i + 1][j] - effect(a[i + 1][j]));
                } else if (j < w - 1) {
                    dp[i][j] = dp[i][j + 1] - effect(a[i][j + 1]);
                } else if (i < h - 1) {
                    dp[i][j] = dp[i + 1][j] - effect(a[i + 1][j]);
                }
            }
        }
    }

    // for (int i = 0; i < h; i++) {
    //     for (int j = 0; j < w; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    if (dp[0][0] > 0) {
        cout << "Takahashi" << endl;
    } else if (dp[0][0] == 0) {
        cout << "Draw" << endl;
    } else {
        cout << "Aoki" << endl;
    }
}
