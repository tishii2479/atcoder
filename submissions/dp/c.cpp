#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int sat[3][110000];
    for (int i = 0; i < n; i++) {
        cin >> sat[0][i] >> sat[1][i] >> sat[2][i];
    }
    int dp[110000][3];
    for (int i = 0; i < 3; i++) {
        dp[0][i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int a1 = (j + 1) % 3;
            int a2 = (j + 2) % 3;
            dp[i + 1][j] = max(dp[i][a1] + sat[a1][i], dp[i][a2] + sat[a2][i]);
        }
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
}