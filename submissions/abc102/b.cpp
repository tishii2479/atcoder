#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> sums(n + 1, 0);
    for (int i = 0; i < n; i++)
        sums[i + 1] = sums[i] + a[i];
    ll ans = 1LL << 61;
    for (int i = 2; i + 2 <= n; i++) {
        ll left_sum = sums[i];
        ll right_sum = sums[n] - left_sum;
        ll P, Q, R, S;
        int l = 0, r = i;
        while (r - l > 1) {
            int m = (r + l) / 2;
            if (abs(left_sum - 2 * sums[m]) > abs(left_sum - 2 * sums[max(0, m - 1)]))
                r = m;
            else
                l = m;
        }
        P = sums[l], Q = left_sum - P;
        l = i + 1, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (abs(right_sum - 2 * (sums[m] - left_sum)) > abs(right_sum - 2 * (sums[max(i + 1, m - 1)] - left_sum)))
                r = m;
            else
                l = m;
        }
        R = sums[l] - left_sum, S = right_sum - R;
        ll mx = max({P, Q, R, S});
        ll mn = min({P, Q, R, S});
        // cout << i << " " << left_sum << " " << right_sum << " " << P << " " << Q << " " << R << " " << S << endl;
        ans = min(ans, abs(mx - mn));
    }
    cout << ans << endl;
}