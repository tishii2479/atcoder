#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll x;
    cin >> x;
    ll sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];

    ll k = 0;
    ll all = x / sum;
    k += all * n;
    x -= sum * all;

    int i = 0;
    while (x >= 0) {
        x -= a[i++];
        k++;
    }
    cout << k << endl;
}
