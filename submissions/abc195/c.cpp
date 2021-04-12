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
    ll n;
    cin >> n;
    ll ans = 0;
    ll cur = 1000;
    ll now = 1;
    while (n >= cur) {
        ans += now * min(n - cur + 1, cur * 1000 - cur);
        cur *= 1000;
        now++;
    }
    cout << ans << endl;
}