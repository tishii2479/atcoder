#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
ll nCk(int n, int k) {
    assert(!(n < k));
    assert(!(n < 0 || k < 0));
    ll res = 1;
    for (ll i = 0; i < k; i++) {
        res *= n - i;
        res /= i + 1;
    }
    return res;
}
int main() {
    ll n, p;
    cin >> n >> p;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll odd = 0;
    ll even = 0;
    ll even_cnt = 1;
    for (ll i = 0; i < n; i++) {
        if (a[i] % 2 == 0)
            even++;
        else
            odd++;
    }
    for (ll i = 0; i < even; i++) {
        even_cnt *= 2LL;
    }
    ll ans = 0;
    for (ll i = 0; i <= odd; i++) {
        if (i % 2 != p)
            continue;
        ans += nCk(odd, i) * even_cnt;
    }
    cout << ans << endl;
}