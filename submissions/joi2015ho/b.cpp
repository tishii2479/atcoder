#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int n;
vector<ll> a;
ll dp[2100][2100];
ll solve(int l, int r, ll s) {
    if (dp[l][r] != -1)
        return dp[l][r];
    if (l == r) {
        if (s)
            return dp[l][r] = 0;
        return dp[l][r] = a[l];
    }
    if (s) {
        if (a[l] > a[r])
            return dp[l][r] = solve((l + 1) % n, r, 0);
        else
            return dp[l][r] = solve(l, (r + n - 1) % n, 0);
    }
    return dp[l][r] = max(solve((l + 1) % n, r, 1) + a[l], solve(l, (r + n - 1) % n, 1) + a[r]);
}
int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < 2100; i++)
        for (int j = 0; j < 2100; j++)
            dp[i][j] = -1;
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, solve((i + 1) % n, (i + n - 1) % n, 1) + a[i]);
    cout << ans << endl;
}