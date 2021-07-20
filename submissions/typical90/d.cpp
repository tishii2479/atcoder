#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) cin >> a[i][j];

    vector<int> y_sum(h, 0), x_sum(w, 0);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            y_sum[i] += a[i][j];
            x_sum[j] += a[i][j];
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            cout << y_sum[i] + x_sum[j] - a[i][j] << " ";
        cout << endl;
    }
}
