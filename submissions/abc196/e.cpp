#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n;
    cin >> n;
    vector<ll> a(n), t(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> t[i];
    int q;
    cin >> q;
    vector<ll> x(q);
    for (int i = 0; i < q; i++)
        cin >> x[i];
    const ll INF = 1LL << 50;
    ll mn = -INF, mx = INF;
    ll add = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] == 1) {
            mn += a[i];
            mx += a[i];
            add += a[i];
        } else if (t[i] == 2) {
            mn = max(mn, a[i]);
            mx = max(mx, a[i]);
        } else {
            mn = min(mn, a[i]);
            mx = min(mx, a[i]);
        }
    }
    for (int i = 0; i < q; i++)
        cout << clamp(x[i] + add, mn, mx) << endl;
}