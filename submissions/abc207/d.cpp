#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i] >> d[i];

    using P = pair<double, double>;

    P cs = {0, 0}, ct = {0, 0};

    for (int i = 0; i < n; i++) {
        cs.first += a[i];
        cs.second += b[i];
        ct.first += c[i];
        ct.second += d[i];
    }

    cs.first /= n;
    cs.second /= n;
    ct.first /= n;
    ct.second /= n;

    for (int i = 0; i < n; i++) {
        a[i] += (ct.first - cs.first);
        b[i] += (ct.second - cs.second);
    }

    auto rotate = [](P center, P p, double ang) -> P {
        double theta = ang * 2 * M_PI / 360;
        double x = p.first, y = p.second;
        double a = center.first, b = center.second;
        double nx = cos(theta) * (x - a) - sin(theta) * (y - b) + a;
        double ny = sin(theta) * (x - a) + cos(theta) * (y - b) + b;
        return P(nx, ny);
    };

    const double eps = 0.01;
    for (double p = 0; p < 360; p += 0.1) {
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            P np = rotate(ct, {a[i], b[i]}, p);
            double x = np.first, y = np.second;
            for (int j = 0; j < n; j++) {
                if (abs(x - c[j]) < eps and abs(y - d[j]) < eps) {
                    cnt++;
                    break;
                }
            }
        }

        if (cnt == n) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}
