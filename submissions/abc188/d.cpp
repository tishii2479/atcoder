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
    ll n, cost;
    cin >> n >> cost;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        mp[a] += c;
        mp[b + 1] -= c;
    }
    ll now = 0;
    ll prev = -1;
    ll sum = 0;
    for (auto m : mp) {
        ll d = m.first;
        ll c = m.second;
        sum += min(cost, now) * (d - prev);
        prev = d;
        now = c + now;
    }
    cout << sum << endl;
}