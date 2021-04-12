#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 10007;
// const int MOD = 998244353;
int ind(char c) {
    if (c == 'J')
        return 0;
    else if (c == 'O')
        return 1;
    return 2;
}
int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<vector<int>> dp(n + 1, vector<int>(1 << 3, 0));
    dp[0][1 << ind('J')] = 1;
    for (int i = 0; i < n; i++) {
        int ad = ind(s[i]);
        for (int bit = 0; bit < (1 << 3); bit++) {
            if ((bit & (1 << ad)) == false)
                continue;
            for (int bit2 = 0; bit2 < (1 << 3); bit2++)
                if (bit & bit2) {
                    dp[i + 1][bit] += dp[i][bit2];
                    dp[i + 1][bit] %= MOD;
                }
        }
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j < 1 << 3; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    int ans = 0;
    for (int i = 0; i < 1 << 3; i++)
        ans += dp[n][i];
    ans %= MOD;
    cout << ans << endl;
}