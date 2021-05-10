#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    ll k, n, m;
    cin >> k >> n >> m;
    vector<ll> a(k);
    for (int i = 0; i < k; i++) cin >> a[i];

    vector<ll> b(k);
    ll sum = 0;
    for (int i = 0; i < k; i++) {
        b[i] = m * a[i] / n;
        sum += b[i];
    }

    ll plus = m - sum;
    vector<int> v(k);

    for (int i = 0; i < k; i++) v[i] = i;

    sort(v.begin(), v.end(), [&](int x, int y) {
        auto f = [&](int i) -> ll {
            return n * b[i] - m * a[i];
        };

        return f(x) < f(y);
    });

    for (int i = 0; i < plus; i++) b[v[i]]++;

    for (int e : b) cout << e << " ";
    cout << endl;
}
