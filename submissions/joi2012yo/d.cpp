#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 10000;
// const int MOD = 998244353;
// 0 = none
int dp[110][4][4];
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k), b(k);
    for (int i = 0; i < k; i++)
        cin >> a[i] >> b[i];
    map<int, int> mp;
    for (int i = 0; i < k; i++)
        mp[a[i]] = b[i];
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        int demand = mp[i + 1];
        if (demand == 0) {
            for (int j = 1; j <= 3; j++)
                for (int m = 0; m <= 3; m++)
                    for (int l = 0; l <= 3; l++) {
                        dp[i + 1][j][m] += dp[i][m][l];
                        dp[i + 1][j][m] %= MOD;
                    }
            for (int j = 1; j <= 3; j++) {
                dp[i + 1][j][j] -= dp[i][j][j];
                dp[i + 1][j][j] %= MOD;
            }
        } else {
            for (int j = 0; j <= 3; j++)
                for (int m = 0; m <= 3; m++) {
                    dp[i + 1][demand][j] += dp[i][j][m];
                    dp[i + 1][demand][j] %= MOD;
                }
            dp[i + 1][demand][demand] -= dp[i][demand][demand];
            dp[i + 1][demand][demand] %= MOD;
        }
    }
    int sum = 0;
    for (int i = 0; i <= 3; i++)
        for (int j = 0; j <= 3; j++)
            sum += dp[n][i][j];
    cout << ((sum % MOD) + MOD) % MOD << endl;
}