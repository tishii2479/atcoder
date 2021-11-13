#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> b(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> b[i][j];

    int left_top = b[0][0];
    bool ok = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int expected = left_top + i * 7 + j;
            if (b[i][j] != expected) ok = false;
        }
        for (int j = 0; j + 1 < m; j++) {
            if (b[i][j] % 7 == 0 and b[i][j + 1] % 7 == 1) ok = false;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}
