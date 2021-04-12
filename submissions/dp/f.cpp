#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int dp[3100][3100];
int main() {
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < t.length(); j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    int i = s.length();
    int j = t.length();
    string ans = "";
    // for (int y = 0; y <= i; y++)
    // {
    //     for (int x = 0; x <= j; x++)
    //         cout << dp[y][x] << " ";
    //     cout << endl;
    // }
    while (i > 0 and j > 0) {
        // cout << i << " " << j << " " << ans << endl;
        if (s[i - 1] != t[j - 1]) {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        } else {
            ans += s[i - 1];
            i--;
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}