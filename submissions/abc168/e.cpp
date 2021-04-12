#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
ll modpow(ll m, ll n) {
    if (n == 1)
        return m;
    if (n == 0)
        return 1;
    ll t = modpow(m, n / 2);
    ll tmp;
    if (n % 2 == 0)
        tmp = (t * t) % MOD;
    else
        tmp = (((t * t) % MOD) * m) % MOD;
    return tmp;
}
ll gcd(ll a, ll b) {
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
int main() {
    ll n;
    cin >> n;
    ll p2[210000];
    p2[0] = 1;
    ll zero = 0;
    map<pll, pll> mp;
    for (int i = 1; i < 210000; i++)
        p2[i] = p2[i - 1] * 2 % MOD;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        if (a == 0 and b == 0)
            zero++;
        else if (a == 0)
            mp[{0, 0}].first++;
        else if (b == 0)
            mp[{0, 0}].second++;
        else {
            if (b < 0)
                a = -a, b = -b;
            ll g = gcd(abs(a), abs(b));
            a /= g;
            b /= g;
            if (a < 0)
                mp[{b, -a}].first++;
            else
                mp[{a, b}].second++;
        }
    }
    ll ret = 1;
    for (auto m : mp) {
        ll a = p2[m.second.first] + p2[m.second.second] - 1;
        ret = ret * a % MOD;
    }
    cout << (ret + zero + MOD - 1) % MOD << endl;
}