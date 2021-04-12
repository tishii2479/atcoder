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
ll n;
vector<ll> a(110000);
vector<ll> cnt(110000, 0);
bool ok() {
    if (n % 2 == 0) {
        for (int i = 1; i < n; i += 2)
            if (cnt[i] != 2)
                return false;
    } else {
        if (cnt[0] != 1)
            return false;
        for (int i = 2; i < n; i += 2)
            if (cnt[i] != 2)
                return false;
    }
    return true;
}
int main() {
    cin >> n;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
        cnt[a[i]]++;
    if (ok() == false) {
        cout << 0 << endl;
    } else {
        cout << modpow(2, n / 2) << endl;
    }
}