#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1; i <= 1100000; i++) {
        ll check = stoll(to_string(i) + to_string(i));
        if (n >= check)
            ans++;
    }
    cout << ans << endl;
}