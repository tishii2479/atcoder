#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int pow2[10];
    pow2[0] = 1;
    for (int i = 0; i < 9; i++) {
        pow2[i + 1] = pow2[i] * 2;
    }
    for (int i = 0; i <= k; i++)
        for (int x = 0; x <= k; x++)
            for (int y = 0; y <= k; y++)
                for (int z = 0; z <= k; z++) {
                    if (x + y + z > k)
                        continue;
                    int na = a * pow2[x];
                    int nb = b * pow2[y];
                    int nc = c * pow2[z];
                    if (nc > nb and nb > na) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
    cout << "No" << endl;
}