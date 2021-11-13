#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    ll x, y;
    cin >> x >> y;

    const int N = 3;
    vector<ll> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    bool found = false;
    for (int _ = 0; _ < 2; _++) {
        for (int bit = 0; bit < (1 << N); bit++) {
            ll remain_x = x;
            for (int i = 0; i < N; i++) {
                if (bit & (1 << i)) remain_x -= (v[i] + y - 1) / y;
            }
            if (remain_x <= 0) continue;

            ll remain_y = y;
            for (int i = 0; i < N; i++) {
                if (bit & (1 << i)) continue;
                remain_y -= (v[i] + remain_x - 1) / remain_x;
            }

            if (remain_y < 0) continue;

            if (!found) {
                cout << "Yes" << endl;
                found = true;
            }
        }

        swap(x, y);
    }

    if (!found) {
        cout << "No" << endl;
    }
}
