#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    ll n;
    cin >> n;
    ll ans = 1LL << 60;
    for (ll b = 0; b < 61; b++) {
        ll val = 1LL << b;
        ll a = n / val;
        ll ab = a * val;
        ll c = n - ab;
        ans = min(ans, a + b + c);
    }
    cout << ans << endl;
}
