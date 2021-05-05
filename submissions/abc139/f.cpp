#include <bits/stdc++.h>
using namespace std;

int main() {
    using pd = pair<double, double>;
    int n;
    cin >> n;
    vector<pd> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;

    sort(p.begin(), p.end(), [&](pd a, pd b) {
        return atan2(a.second, a.first) < atan2(b.second, b.first);
    });

    double ans = 0;
    for (int i = 0; i < n; i++) {
        p.push_back(p[i]);
    }

    for (int wid = 1; wid <= n; wid++) {
        for (int l = 0; l < n; l++) {
            int r = l + wid;
            double x = 0, y = 0;

            for (int i = l; i < r; i++) {
                x += p[i].first;
                y += p[i].second;
            }

            ans = max(ans, sqrt(x * x + y * y));
        }
    }

    cout << fixed << setprecision(10) << ans << endl;
}
