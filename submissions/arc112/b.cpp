#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    ll b, c;
    cin >> b >> c;
    ll l1 = b - c / 2;
    ll r1 = b + (c - 2) / 2;
    ll l2 = -b - (c - 1) / 2;
    ll r2 = -b + (c - 1) / 2;
    ll ans = min(max(r1, r2) - min(l1, l2) + 1, r2 - l2 + r1 - l1 + 2);
    cout << ans << endl;
}