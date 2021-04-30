#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long double> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    const long double eps = 1e-10;
    const int mx = 100;
    long double left = eps, right = 1e6;
    int cnt = 0;

    while (cnt < mx and right - left > eps) {
        long double r = (left + right) / 2;
        vector<pair<long double, long double>> points;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long double dy = y[j] - y[i], dx = x[j] - x[i];
                long double dist = sqrtl(dy * dy + dx * dx);
                dx /= dist, dy /= dist;
                long double theta = acos(dist / 2 / r);
                if (isnan(theta)) continue;
                long double px = x[i] + (cos(theta) * dx - sin(theta) * dy) * r;
                long double py = y[i] + (sin(theta) * dx + cos(theta) * dy) * r;
                points.push_back({px, py});
                theta *= -1;
                long double px2 = x[i] + (cos(theta) * dx - sin(theta) * dy) * r;
                long double py2 = y[i] + (sin(theta) * dx + cos(theta) * dy) * r;
                points.push_back({px2, py2});
            }
        }

        bool ok = false;

        for (int i = 0; i < points.size(); i++) {
            long double cx = points[i].first, cy = points[i].second;
            bool flag = true;
            for (int j = 0; j < n; j++) {
                long double dx = x[j] - cx, dy = y[j] - cy;
                if (sqrtl(dx * dx + dy * dy) > r + eps) flag = false;
            }
            if (flag) ok = true;
        }

        if (ok) {
            right = r;
        } else {
            left = r;
        }
        cnt++;
    }

    cout << fixed << setprecision(15) << right << endl;
}
