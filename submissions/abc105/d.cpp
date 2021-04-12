#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
ll f(ll a) {
    if (a < 2)
        return 0;
    return a * (a - 1) / 2;
}
int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll cur = 0;
    map<ll, ll> mp;
    mp[0] = 1;
    for (int i = 0; i < n; i++) {
        cur += a[i];
        cur %= m;
        mp[cur]++;
    }
    ll res = 0;
    for (auto m : mp) {
        // cout << m.first << " " << m.second << endl;
        res += f(m.second);
    }
    cout << res << endl;
}