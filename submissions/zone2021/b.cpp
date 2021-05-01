#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, D, H;
    cin >> N >> D >> H;
    vector<pair<int, int>> p(N);
    for (int i = 0; i < N; i++) cin >> p[i].first >> p[i].second;

    double ans = 0;

    for (int i = 0; i < N; i++) {
        int d = p[i].first, h = p[i].second;
        ans = max(ans, h + (double)d * (h - H) / (D - d));
    }

    cout << fixed << setprecision(10) << ans << endl;
}
