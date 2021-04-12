#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
ll dp[110][10];
vector<ll> memo(10, -1);
ll f(ll x) {
    if (x <= 0)
        return 1;
    if (memo[x] != -1)
        return memo[x];
    ll res = 0;
    for (int i = 0; i < 1 << x; i++) {
        vector<int> add;
        for (int j = 0; j < x; j++) {
            if (i & (1 << j))
                add.push_back(j);
        }
        int prev = -2;
        for (int j = 0; j < add.size(); j++) {
            if (prev + 1 == add[j]) {
                res--;
                break;
            }
            prev = add[j];
        }
        res++;
    }
    return memo[x] = (res % MOD);
}
int main() {
    int h, w, k;
    cin >> h >> w >> k;
    dp[0][1] = 1;
    for (int i = 0; i < h; i++) {
        for (int j = 1; j <= w; j++) {
            ll d = dp[i][j - 1] * f(j - 3) * f(w - j - 1);
            d %= MOD;
            ll e = dp[i][j + 1] * f(j - 2) * f(w - j - 2);
            e %= MOD;
            ll c = dp[i][j] * f(j - 2) * f(w - j - 1);
            c %= MOD;
            dp[i + 1][j] = d + e + c;
            dp[i + 1][j] %= MOD;
        }
    }
    // for (int i = 0; i <= h; i++)
    // {
    //     for (int j = 0; j <= w + 1; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[h][k] << endl;
}