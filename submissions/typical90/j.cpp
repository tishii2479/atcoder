#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
    int q;
    cin >> q;
    vector<vector<int>> sums(2, vector<int>(n + 1, 0));

    for (int i = 0; i < n; i++) {
        sums[0][i + 1] = sums[0][i];
        sums[1][i + 1] = sums[1][i];
        sums[p[i].first - 1][i + 1] += p[i].second;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        cout << sums[0][r] - sums[0][l] << " " << sums[1][r] - sums[1][l] << endl;
    }
}
