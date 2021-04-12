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
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> sum(n + 1, 0);
    for (int i = 0; i < n; i++)
        sum[i + 1] = sum[i] + a[i];
    ll ans = INF;
    for (int i = 1; i < n; i++) {
        ll l = sum[i];
        ll r = sum[n] - sum[i];
        ans = min(ans, max(l, r) - min(l, r));
    }
    cout << ans << endl;
}