#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, ans;
vector<ll> a;
bool ok(ll x) {
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(a.begin(), a.end(), x - a[i]) - a.begin();
        cnt += (n - pos);
    }
    return cnt < m;
}
int main() {
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    ll l = 0, r = (1LL << 60);
    while (r - l > 1) {
        ll x = (r + l) / 2;
        if (ok(x))
            r = x;
        else
            l = x;
    }
    vector<ll> sums(n + 1, 0);
    for (int i = 0; i < n; i++)
        sums[i + 1] = sums[i] + a[i];
    for (int i = 0; i < n; i++) {
        int pos = upper_bound(a.begin(), a.end(), l - a[i]) - a.begin();
        ll cnt = n - pos;
        ans += cnt * a[i] + (sums[n] - sums[pos]);
        m -= cnt;
    }
    ans += m * l;
    cout << ans << endl;
}