#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
vector<pll> prime_factorize(ll n) {
    vector<pll> res;
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p != 0)
            continue;
        int num = 0;
        while (n % p == 0) {
            ++num;
            n /= p;
        }
        res.push_back(make_pair(p, num));
    }
    if (n != 1)
        res.push_back(make_pair(n, 1));
    return res;
}
int main() {
    int n;
    ll d;
    cin >> n >> d;
    auto vec = prime_factorize(d);
    map<int, int> mp;
    for (auto p : vec) {
        if (p.first > 6) {
            cout << 0 << endl;
            return 0;
        }
        if (p.first == 1)
            continue;
        mp[p.first] = p.second;
    }
    vector<vector<vector<double>>> dp(mp[2] + 1, vector<vector<double>>(mp[3] + 1, vector<double>(mp[5] + 1, 0)));
    int d2[6] = {0, 1, 0, 2, 0, 1};
    int d3[6] = {0, 0, 1, 0, 0, 1};
    int d5[6] = {0, 0, 0, 0, 1, 0};
    dp[0][0][0] = 1;
    for (int _ = 0; _ < n; _++) {
        vector<vector<vector<double>>> tmp(mp[2] + 1, vector<vector<double>>(mp[3] + 1, vector<double>(mp[5] + 1, 0)));
        for (int i = 0; i <= mp[2]; i++)
            for (int j = 0; j <= mp[3]; j++)
                for (int k = 0; k <= mp[5]; k++)
                    for (int x = 0; x < 6; x++) {
                        int ni = min(mp[2], i + d2[x]);
                        int nj = min(mp[3], j + d3[x]);
                        int nk = min(mp[5], k + d5[x]);
                        tmp[ni][nj][nk] += dp[i][j][k] / 6;
                    }
        swap(dp, tmp);
    }
    cout << fixed << setprecision(10);
    cout << dp[mp[2]][mp[3]][mp[5]] << endl;
}