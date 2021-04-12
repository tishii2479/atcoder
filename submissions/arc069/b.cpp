#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
// 0 = S, 1 = W
int dp[210000][4];
int main() {
    int n;
    string s;
    cin >> n >> s;
    s = s + s;
    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[0][1] = 1;
    dp[1][1] = 0;
    dp[0][2] = 0;
    dp[1][2] = 1;
    dp[0][3] = 1;
    dp[1][3] = 1;
    for (int i = 1; i < s.size(); i++) {
        for (int j = 0; j < 4; j++) {
            if (s[i] == 'o') {
                if (dp[i][j] == 0) {
                    dp[i + 1][j] = dp[i - 1][j];
                } else {
                    dp[i + 1][j] = 1 - dp[i - 1][j];
                }
            } else {
                if (dp[i][j] == 0) {
                    dp[i + 1][j] = 1 - dp[i - 1][j];
                } else {
                    dp[i + 1][j] = dp[i - 1][j];
                }
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        if (dp[0][i] == dp[n][i] and dp[1][i] == dp[n + 1][i]) {
            for (int j = 0; j < n; j++) {
                cout << (dp[j][i] ? 'W' : 'S');
            }
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}