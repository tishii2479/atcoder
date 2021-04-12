#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
// const int MOD = 1000000007;
// const int MOD = 998244353;
const ll MOD = 1000000007;
ll dp[110000][15];
int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    ll n = s.length();
    ll now = 1;
    dp[0][0] = 1;
    for (ll i = 0; i < n; i++) {
        // cout << i << endl;
        if (s[i] == '?') {
            for (ll j = 0; j < 13; j++) {
                for (ll k = 0; k < 10; k++) {
                    dp[i + 1][(j + k * now) % 13] += dp[i][j];
                    dp[i + 1][(j + k * now) % 13] %= (MOD * 13);
                }
            }
        } else {
            ll a = s[i] - '0';
            for (ll j = 0; j < 13; j++) {
                dp[i + 1][(j + a * now) % 13] += dp[i][j];
                dp[i + 1][(j + a * now) % 13] %= (MOD * 13);
            }
        }
        // cout << s[i] << endl;
        // for (int j = 0; j < 13; j++)
        // {
        //     cout << dp[i + 1][j] << " ";
        // }
        // cout << endl;
        now *= 10;
        now %= MOD * 13;
    }
    cout << dp[n][5] % MOD << endl;
}