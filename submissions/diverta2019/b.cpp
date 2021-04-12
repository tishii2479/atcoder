#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int R, B, G, n;
    cin >> R >> G >> B >> n;
    ll ans = 0;
    for (int r = 0; r <= n / R; r++)
        for (int b = 0; b <= n / B; b++) {
            int rcnt = r * R;
            int bcnt = b * B;
            int gcnt = (n - rcnt - bcnt);
            if (gcnt % G != 0)
                continue;
            if (gcnt < 0)
                continue;
            ans++;
        }
    cout << ans << endl;
}