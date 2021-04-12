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
    Int a[4];
    Int sum = 0;
    rep(i, 4) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 2 == 1) {
        cout << "No" << endl;
        return 0;
    }
    sum /= 2;
    rep(i, 1 << 4) {
        Int tmp = 0;
        rep(j, 4) {
            if (i & 1 << j) {
                tmp += a[j];
            }
        }
        if (tmp == sum) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}