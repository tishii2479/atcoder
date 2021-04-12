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
    int n;
    cin >> n;
    string s[5];
    for (int i = 0; i < 5; i++)
        cin >> s[i];
    vector<vector<int>> flag(5, vector<int>(n));
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < n; j++) {
            if (s[i][j] == 'R')
                flag[i][j] = 0;
            else if (s[i][j] == 'B')
                flag[i][j] = 1;
            else if (s[i][j] == 'W')
                flag[i][j] = 2;
            else
                flag[i][j] = 3;
        }
    // dp[current_row][color]
    vector<vector<int>> dp(n + 1, vector<int>(4, inf));
    for (int i = 0; i < 3; i++)
        dp[0][i] = 0;
    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //         cout << flag[i][j] << " ";
    //     cout << endl;
    // }
    int ans = inf;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int cost = 0;
            for (int k = 0; k < 5; k++) {
                if (flag[k][i] != j)
                    cost++;
            }
            int mn = inf;
            for (int k = 0; k < 3; k++) {
                if (k == j)
                    continue;
                mn = min(mn, dp[i][k]);
            }
            // cout << i << " " << j << " " << mn << " " << cost << endl;
            dp[i + 1][j] = mn + cost;
        }
    }
    for (int i = 0; i < 3; i++)
        ans = min(ans, dp[n][i]);
    cout << ans << endl;
}