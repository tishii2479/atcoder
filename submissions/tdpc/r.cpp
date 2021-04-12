#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
// keta, mod n, smaller
// 0 = equal, 1 = smaller
int dp[11000][100][2];
int main() {
    int d;
    string s;
    cin >> d >> s;
    int n = s.length();
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        int num = s[i] - '0';
        for (int j = 0; j < d; j++) {
            for (int k = 0; k < 10; k++) {
                dp[i + 1][(j + k) % d][1] += dp[i][j][1];
                if (k < num)
                    dp[i + 1][(j + k) % d][1] += dp[i][j][0];
                else if (k == num)
                    dp[i + 1][(j + k) % d][0] += dp[i][j][0];
                dp[i + 1][(j + k) % d][0] %= MOD;
                dp[i + 1][(j + k) % d][1] %= MOD;
            }
        }
    }
    cout << dp[n][0][0] + dp[n][0][1] - 1 << endl;
}