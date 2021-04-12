#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    for (ll b = k + 1; b <= n; b++) {
        ll mx = n / b;
        ll cnt = b - k;
        ans += cnt * mx;
        ans += max(0LL, n - mx * b - k + (k != 0));
    }
    cout << ans << endl;
}