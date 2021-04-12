#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
string s[100];
ll dp[100][2];
int main() {
    int n;
    cin >> n;
    bool hasAnd = false;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (s[i] == "AND") {
            hasAnd = true;
        }
    }
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == "AND") {
            dp[i + 1][0] = dp[i][1] + dp[i][0] * 2;
            dp[i + 1][1] = dp[i][1];
        } else {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = dp[i][0] + dp[i][1] * 2;
        }
    }
    cout << dp[n][1] << endl;
}