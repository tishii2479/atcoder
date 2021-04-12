#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repd(i, n) for (int i = n - 1; i >= 0; i--)
// #define MOD 1000000007
#define MOD 998244353
const Int INF = 1LL << 60;
const int inf = 1 << 29;
int main() {
    Int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int ans;
    if (r1 == r2 and c1 == c2) {
        ans = 0;
    } else if (abs(r1 - r2) + abs(c1 - c2) <= 3) {
        ans = 1;
    } else if (abs(r1 - r2) == abs(c1 - c2)) {
        ans = 1;
    } else if (abs(r1 - r2) % 2 == abs(c1 - c2) % 2) {
        ans = 2;
    } else if (abs(abs(r1 - r2) - abs(c1 - c2)) <= 3) {
        ans = 2;
    } else {
        ans = 3;
    }
    cout << ans << endl;
}