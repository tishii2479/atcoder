#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#define MOD 1000000007
// #define MOD 998244353
using namespace std;
typedef long long ll;
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> r(n + 1);
    vector<ll> rmax(n + 1, 0);
    r[0] = 0;
    rmax[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        r[i + 1] = r[i] + a[i];
        rmax[i + 1] = max(r[i + 1], rmax[i]);
    }
    vector<ll> dp(n + 1);
    dp[0] = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, max(dp[i], dp[i] + rmax[i + 1]));
        dp[i + 1] = dp[i] + r[i + 1];
    }
    cout << ans << endl;
}