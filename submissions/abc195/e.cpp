#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n;
    string str1, str2;
    cin >> n >> str1 >> str2;
    vector<int> s(n), x(n);
    for (int i = 0; i < n; i++)
        s[i] = str1[i] - '0';
    for (int i = 0; i < n; i++)
        x[i] = (str2[i] != 'T');
    // T = 0, A = 1
    vector<vector<int>> dp(n + 1, vector<int>(7, 1));
    dp[n][0] = 0;
    for (int i = n - 1; i >= 0; i--)
        for (int r = 0; r < 7; r++) {
            if (dp[i + 1][(r * 10 + s[i]) % 7] == x[i] or dp[i + 1][r * 10 % 7] == x[i])
                dp[i][r] = x[i];
            else
                dp[i][r] = 1 - x[i];
        }
    cout << (dp[0][0] == 0 ? "Takahashi" : "Aoki") << endl;
}