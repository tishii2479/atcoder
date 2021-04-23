#include <bits/stdc++.h>
using namespace std;

int main() {
    struct P {
        int x, y;
    };
    const double pi = M_PI;
    const double eps = 1e-10;
    long long n;
    cin >> n;
    vector<P> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;

    // eikaku, chokkaku, donkaku
    vector<long long> ans(3, 0);

    for (int i = 0; i < n; i++) {
        vector<double> rad;
        for (int j = 0; j < n; j++)
            if (i != j) rad.push_back(atan2(p[j].y - p[i].y, p[j].x - p[i].x));
        sort(rad.begin(), rad.end());
        for (int j = 0; j < n; j++)
            rad.push_back(rad[j] + 2.0 * pi);

        int l = 1, r = 1;
        for (int j = 0; j < n - 1; j++) {
            while (rad[l] - rad[j] < pi / 2 - eps) l++;
            while (rad[r] - rad[j] <= pi + eps) r++;
            if (rad[l] - rad[j] <= pi / 2 + eps) ans[1]++, l++;
            ans[2] += r - l;
        }
    }
    ans[0] = n * (n - 1) * (n - 2) / 6 - ans[1] - ans[2];
    cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
}
