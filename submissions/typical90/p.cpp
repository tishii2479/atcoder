#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    const int N = 10000;
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    ll ans = 1 << 30;

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            ll sum = a * i + b * j;
            ll need = n - sum;
            if (need < 0) continue;
            if (need % c != 0) continue;
            ll cnt = i + j + need / c;
            ans = min(cnt, ans);
        }
    }

    cout << ans << endl;
}
