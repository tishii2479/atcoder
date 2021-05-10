#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    ll n, m;
    cin >> n >> m;
    ll ans = min(n, m / 2);
    ans += (m - min(n, m / 2) * 2) / 4;
    cout << ans << endl;
}
