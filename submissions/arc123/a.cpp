#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    ll a[3];
    for (int i = 0; i < 3; i++) cin >> a[i];

    ll val = 2 * a[1] - (a[0] + a[2]);
    if (val <= 0) {
        ll cnt = -val;
        if (cnt % 2 == 1) cnt += 3;
        cout << cnt / 2 << endl;
    } else {
        cout << val << endl;
    }
}
