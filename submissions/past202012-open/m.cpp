#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;

int main() {
    using ll = long long;
    int n;
    ll l;
    cin >> n >> l;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> sums(n + 1, 0);
    for (int i = 0; i < n; i++) sums[i + 1] += sums[i] + a[i];

    ll left = 0, right = l;

    while (right - left > 1) {
        ll m = (left + right) / 2;

        atcoder::fenwick_tree<int> bit(n + 1);
        bit.add(0, 1);

        for (int i = 0; i < n; i++) {
            if (sums[i + 1] < m) continue;

            int a = lower_bound(sums.begin(), sums.end(), sums[i + 1] - l) - sums.begin();
            int b = lower_bound(sums.begin(), sums.end(), sums[i + 1] - m) - sums.begin();

            if (a > b) continue;
            if (bit.sum(a, b) > 0) bit.add(i + 1, 1);
        }

        if (bit.sum(n, n + 1)) {
            left = m;
        } else {
            right = m;
        }
    }

    cout << right << endl;
}
