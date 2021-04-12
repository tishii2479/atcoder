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
    ll k;
    cin >> k;
    ll ans = 0;
    for (ll a = 1; a <= k; a++) {
        for (ll b = 1; a * b <= k; b++) {
            ll c = k / (a * b);
            ans += c;
        }
    }
    cout << ans << endl;
}