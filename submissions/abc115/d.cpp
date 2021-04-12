#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
vector<ll> cnt(60, -1);
ll height[60];
// nagasa, level
ll dfs(ll x, ll n) {
    if (x == 0)
        return 0;
    if (n == 0)
        return 1;
    if (cnt[n] != -1)
        return cnt[n];
    ll c = 0;
    if (x > height[n - 1] + 2) {
        c += dfs(x - height[n - 1] - 2, n - 1);
    }
    if (x > (height[n - 1] + 1))
        c++;
    if (x > height[n - 1]) {
        cnt[n - 1] = dfs(height[n - 1], n - 1);
        c += cnt[n - 1];
    } else if (x > 1) {
        c += dfs(min(height[n - 1], x - 1), n - 1);
    }
    return c;
}
int main() {
    int n;
    ll x;
    cin >> n >> x;
    height[0] = 1;
    for (int i = 0; i < n; i++) {
        height[i + 1] = height[i] * 2 + 3;
    }
    cout << dfs(x, n) << endl;
}