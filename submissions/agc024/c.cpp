#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const ll inf = 1 << 30;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
ll n;
vector<ll> a;
ll solve() {
    for (ll i = 0; i < n; i++)
        if (a[i] > i)
            return -1;
    vector<ll> res(n, 0);
    ll cur = 0;
    for (ll i = n - 1; i >= 0; i--) {
        if (cur > a[i])
            return -1;
        if (cur == a[i]) {
            cur--;
            continue;
        }
        res[i] = a[i];
        cur = max(0LL, a[i] - 1);
    }
    ll ans = 0;
    for (ll r : res) {
        ans += r;
    }
    return ans;
}
int main() {
    cin >> n;
    a.resize(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    cout << solve() << endl;
}