#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> sums(n + 1, 0);
    for (int i = 0; i < n; i++) sums[i + 1] = sums[i] + a[i];
    ll ans = 1LL << 60;
    for (int i = 1; i < n; i++) {
        ans = min(ans, abs(sums[n] - 2 * sums[i]));
    }
    cout << ans << endl;
}