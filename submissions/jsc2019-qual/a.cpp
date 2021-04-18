#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, d;
    cin >> m >> d;
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= d; j++) {
            if (j < 10) continue;
            string str = to_string(j);
            int d1 = str[1] - '0', d10 = str[0] - '0';
            if (d1 < 2 or d10 < 2) continue;
            if (i == d1 * d10) ans++;
        }
    }
    cout << ans << endl;
}
