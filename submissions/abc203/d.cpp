#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];

    int l = -1, r = 1e9 + 100;

    while (r - l > 1) {
        int m = (l + r) / 2;
        vector<vector<int>> sums(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[i][j] <= m) sums[i + 1][j + 1] = 1;

        for (int i = 0; i < n; i++)
            for (int j = 0; j <= n; j++) sums[i + 1][j] += sums[i][j];

        for (int i = 0; i <= n; i++)
            for (int j = 0; j < n; j++) sums[i][j + 1] += sums[i][j];

        bool ok = false;

        for (int i = 0; i + k <= n; i++)
            for (int j = 0; j + k <= n; j++) {
                int val = sums[i + k][j + k] - sums[i][j + k] - sums[i + k][j] + sums[i][j];
                if (val >= k * k - k * k / 2) ok = true;
                // cout << i << " " << j << " " << m << " " << val << endl;
            }

        if (ok)
            r = m;
        else
            l = m;
    }

    cout << r << endl;
}
