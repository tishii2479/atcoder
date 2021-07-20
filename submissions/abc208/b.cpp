#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    ll p;
    cin >> p;
    const int N = 11;
    vector<ll> v(N, 1);
    for (int i = 1; i + 1 < N; i++) {
        v[i + 1] = v[i] * (i + 1);
    }

    ll cnt = 0;

    for (int i = N - 1; i >= 1; i--) {
        ll val = p / v[i];
        if (val == 0) continue;
        p -= val * v[i];
        cnt += val;
    }

    assert(p == 0);
    cout << cnt << endl;
}
