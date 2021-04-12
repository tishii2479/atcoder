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
Int mpow(Int x, Int n) {
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return mpow(x * x, n / 2);
    return x * mpow(x, n - 1);
}
int main() {
    Int n;
    cin >> n;
    for (Int i = 1; i <= 48; i++) {
        if (mpow(3, i) > n)
            break;
        for (Int j = 1; j <= 36; j++) {
            if (mpow(5, j) > n)
                break;
            if (mpow(3, i) + mpow(5, j) == n) {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}