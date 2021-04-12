#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
ll n;
vector<ll> h, s;
bool ok(ll x) {
    vector<ll> limit(n, 0);
    for (int i = 0; i < n; i++) {
        if (x < h[i])
            return false;
        ll l = min(n - 1, (x - h[i]) / s[i]);
        limit[l]++;
    }
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        cur += limit[i];
        if (cur > i + 1)
            return false;
    }
    return true;
}
int main() {
    cin >> n;
    h.resize(n);
    s.resize(n);
    for (int i = 0; i < n; i++)
        cin >> h[i] >> s[i];
    ll l = 0, r = INF;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (ok(m))
            r = m;
        else
            l = m;
    }
    cout << r << endl;
}