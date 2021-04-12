#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1; i * i < n; i++) {
        if (n % i == 0 and (n / i) - 1 > i) {
            ans += n / i - 1;
        }
    }
    cout << ans << endl;
}