#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long Int;
#define pint pair<int, int>
#define each(i, mp) for (auto &i : mp)
#define rep(i, n) for (Int i = 0; i < n; i++)
#define repd(i, n) for (Int i = n - 1; i >= 0; i--)
#define MOD 1000000007
// #define MOD 998244353
const Int INF = 1LL << 60;
const int inf = 1 << 29;
int main() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    Int ans;
    if (b >= a) {
        ans = min((b - a) * y + x, ((b - a) * 2 + 1) * x);
    } else {
        ans = min(x * (2 * (a - b) - 1), x + y * (a - b - 1));
    }
    cout << ans << endl;
}