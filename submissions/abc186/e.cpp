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
ll gcd(ll a, ll b) {
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
int solve() {
    ll n, s, k;
    cin >> n >> s >> k;
    auto p = crt({0, n - s}, {k, n});
    if (p.second == 0)
        return -1;
    return p.first / k;
}
int main() {
    int t;
    cin >> t;
    while (t--)
        cout << solve() << endl;
}