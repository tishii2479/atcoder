#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
bool isAble(int a, int b, int t) {
    for (int ai = 0; ai * a <= t; ai++) {
        for (int bi = 0; bi * b <= t; bi++) {
            if (ai * a + bi * b == t) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    double mx = -1;
    int maxall = 0;
    int maxsugar = 0;
    for (int i = 100 * a; i <= f; i += 100) {
        int j = i / 100;  // aai + bbi = i; c + d = j;
        if (isAble(a, b, j) == false)
            continue;
        int water = i;
        int sugarmax = min(f - water, j * e);
        int s;
        for (s = sugarmax; s >= 0; s--) {
            if (isAble(c, d, s))
                break;
        }
        if (s < 0)
            continue;
        if (i + s > f)
            continue;
        double ratio = (double)s / (s + water);
        if (ratio > mx) {
            maxall = s + water;
            maxsugar = s;
            mx = ratio;
        }
    }
    cout << maxall << " " << maxsugar << endl;
}