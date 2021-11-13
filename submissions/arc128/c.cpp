#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    ll n, _m, _s;
    cin >> n >> _m >> _s;
    long double s = _s, m = _m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long double> res(n);
    for (int i = n - 1; i >= 0; i--) {
        long double max_value = 0;
        int max_index = 0;
        long double sum = 0;
        for (int j = i; j >= 0; j--) {
            sum += a[j];
            if (sum / (i - j + 1) > max_value) {
                max_index = j;
                max_value = sum / (i - j + 1);
            }
        }

        long double tmp = s;
        for (int j = max_index; j <= i; j++) {
            res[j] = min(m, tmp / (i - max_index + 1));
            s -= res[j];
        }

        i = max_index;
    }

    long double ans = 0;
    for (int i = 0; i < n; i++) ans += res[i] * a[i];
    cout << fixed << setprecision(10) << ans << endl;
}
