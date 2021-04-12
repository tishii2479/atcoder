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
#define each(i, mp) for (auto &i : mp)
#define rep(i, n) for (Int i = 0; i < n; i++)
#define repd(i, n) for (Int i = n - 1; i >= 0; i--)
#define MOD 1000000007
// #define MOD 998244353
const Int INF = 1LL << 60;
const int inf = 1 << 29;
int main() {
    int n, m;
    cin >> n >> m;
    int a[1100];
    int ans = 0;
    int sum = 0;
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    rep(i, n) {
        if ((double)a[i] < (double)sum / (4 * m))
            continue;
        ans++;
    }
    if (ans >= m) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}