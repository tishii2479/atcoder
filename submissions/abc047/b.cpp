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
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> maxs(n, INF);
    ll mx = a[n - 1];
    for (int i = n - 1; i >= 0; i--) {
        mx = max(mx, a[i]);
        maxs[i] = mx;
    }
    map<ll, int, greater<ll>> mp;
    for (int i = 0; i < n; i++) {
        mp[maxs[i] - a[i]]++;
    }
    // for (auto m : mp)
    // {
    //     cout << m.first << " " << m.second << endl;
    // }
    cout << (*mp.begin()).second << endl;
}