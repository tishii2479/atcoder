#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> r(n), c(n), a(n);
    map<int, vector<int>, greater<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> r[i] >> c[i] >> a[i];
        mp[a[i]].push_back(i);
    }

    vector<int> res(n);
    vector<int> r_max(h + 1), c_max(w + 1);
    for (auto [val, vec] : mp) {
        for (auto i : vec) res[i] = max(r_max[r[i]], c_max[c[i]]);
        for (auto i : vec) {
            r_max[r[i]] = max(r_max[r[i]], res[i] + 1);
            c_max[c[i]] = max(c_max[c[i]], res[i] + 1);
        }
    }

    for (int i = 0; i < n; i++) cout << res[i] << endl;
}
