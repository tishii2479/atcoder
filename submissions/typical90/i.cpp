#include <bits/stdc++.h>
using namespace std;

int main() {
    const long double PI = M_PI;
    int n;
    cin >> n;
    struct P {
        int x, y;
    };

    vector<P> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
    long double ans = 0;
    for (int i = 0; i < n; i++) {
        vector<long double> rad;
        for (int j = 0; j < n; j++)
            if (i != j) rad.push_back(atan2(p[j].y - p[i].y, p[j].x - p[i].x));
        sort(rad.begin(), rad.end());
        for (int j = 0; j < n - 1; j++)
            rad.push_back(rad[j] + 2 * PI);

        int border = 1;
        for (int j = 0; j < n - 1; j++) {
            while (rad[border] - rad[j] <= PI) border++;
            long double x1 = (rad[border] - rad[j]) * 360 / (2 * PI);
            long double x2 = (rad[border - 1] - rad[j]) * 360 / (2 * PI);
            while (x1 > 360) x1 -= 180;
            while (x2 > 360) x2 -= 180;
            if (x1 > 180) x1 = 360 - x1;
            if (x2 > 180) x2 = 360 - x2;
            // cout << x1 << " " << x2 << endl;

            ans = max({ans, x1, x2});
        }
    }

    cout << fixed << setprecision(15) << ans << endl;
}
