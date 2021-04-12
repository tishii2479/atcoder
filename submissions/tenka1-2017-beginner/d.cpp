#include <bits/stdc++.h>
using namespace std;
int main() {
    using ll = long long;
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    ll ans = 0;
    for (int j = 0; j < n; j++)
        if (a[j] == (k & a[j])) ans += b[j];
    for (int i = 0; i < 40; i++) {
        if (!(k & (1 << i))) continue;
        ll cur = 0;
        int x = (k | (1 << i) - 1) - (1 << i);
        for (int j = 0; j < n; j++) {
            if (a[j] == (x & a[j])) cur += b[j];
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
}