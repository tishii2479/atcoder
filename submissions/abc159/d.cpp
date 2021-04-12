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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
        mp[a[i]]++;
    ll mx = 0;
    for (auto m : mp)
        mx += m.second * (m.second - 1) / 2;
    for (ll i = 0; i < n; i++) {
        ll cnt = mp[a[i]];
        if (cnt <= 1)
            cout << mx << endl;
        else
            cout << mx - cnt * (cnt - 1) / 2 + (cnt - 1) * (cnt - 2) / 2 << endl;
    }
}