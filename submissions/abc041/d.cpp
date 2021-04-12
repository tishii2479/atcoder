#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool bad[20][20];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        bad[y][x] = true;
    }
    vector<ll> dp(1 << n, 0);
    dp[0] = 1;
    for (int bit = 0; bit < (1 << n); bit++) {
        for (int j = 0; j < n; j++) {
            if ((bit & (1 << j)) == false) {
                bool ok = true;
                for (int k = 0; k < n; k++) {
                    if (bit & (1 << k))
                        if (bad[k][j]) ok = false;
                }
                if (ok) {
                    dp[bit | (1 << j)] += dp[bit];
                }
            }
        }
    }
    cout << dp[(1 << n) - 1] << endl;
}