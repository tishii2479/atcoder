#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
ll modpow(ll a, ll n, ll m = MOD) {
    if (n == 0)
        return 1;
    ll t = modpow(a, n / 2, m);
    if (n % 2 == 0)
        return (t * t) % m;
    else
        return (((t * t) % m) * a) % m;
}
int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << modpow(a, modpow(b, c, 4) + 4, 10) << endl;
}