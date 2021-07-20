#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = 0;

    for (int i = 0; i < n; i++) ans += abs(a[i] - b[i]);
    cout << ans << endl;
}
