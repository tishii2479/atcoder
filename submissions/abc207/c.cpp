#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, pair<double, double>>> v(n);
    for (int i = 0; i < n; i++) {
        int t;
        double l, r;
        cin >> t >> l >> r;
        if (t == 1) {
        } else if (t == 2) {
            r -= 0.4;
        } else if (t == 3) {
            l += 0.4;
        } else {
            l += 0.4;
            r -= 0.4;
        }
        v[i].first = t;
        v[i].second.first = l;
        v[i].second.second = r;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double min_r = min(v[i].second.second, v[j].second.second);
            double max_l = max(v[i].second.first, v[j].second.first);
            // cout << i << " " << j << " ";
            // cout << min_r << " " << max_l << endl;

            if (min_r >= max_l) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
