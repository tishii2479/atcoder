#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    ll n;
    cin >> n;

    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    int ans = n * (n - 1) * (n - 2) / 6;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++) {
                vector<pair<ll, ll>> v{
                    {x[i], y[i]},
                    {x[j], y[j]},
                    {x[k], y[k]}};

                sort(v.begin(), v.end());

                ll dx1 = v[1].first - v[0].first, dx2 = v[2].first - v[0].first;
                ll dy1 = v[1].second - v[0].second, dy2 = v[2].second - v[0].second;
                if (dx1 * dy2 == dx2 * dy1) {
                    // cout << i << " " << j << " " << k << endl;
                    ans--;
                }
            }

    cout << ans << endl;
}
