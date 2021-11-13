#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> a(n), b(n);
    double sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        sum += a[i];
    }

    double l = 0, r = 1e10;
    for (int _ = 0; _ < 500; _++) {
        double m = (l + r) / 2;
        double left = 0, right = sum;
        double t = 0;
        for (int i = 0; i < n; i++) {
            if (t + a[i] / b[i] <= m) {
                t += a[i] / b[i];
                left += a[i];
            } else {
                left += (m - t) * b[i];
                break;
            }
        }

        t = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (t + a[i] / b[i] <= m) {
                t += a[i] / b[i];
                right -= a[i];
            } else {
                right -= (m - t) * b[i];
                break;
            }
        }

        if (left < right) {
            l = m;
        } else {
            r = m;
        }

        if (_ == 499) {
            cout << fixed << setprecision(15) << right << endl;
        }
    }
}
