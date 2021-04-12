#include <bits/stdc++.h>
using namespace std;
int main() {
    using ll = long long;
    ll n;
    cin >> n;
    ll all = 0;
    ll cur = 0;
    for (ll i = 1; i <= n; i++) {
        cur += i;
        all += cur;
    }
    for (int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        all -= u * (n - v + 1);
    }
    cout << all << endl;
}