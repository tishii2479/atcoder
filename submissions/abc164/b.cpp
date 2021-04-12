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
#define MOD 1000000007
// #define MOD 998244353
const Int INF = 1LL << 60;
const int inf = 1 << 29;
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    while (a > 0 and c > 0) {
        c -= b;
        if (c <= 0) {
            cout << "Yes" << endl;
            return 0;
        }
        a -= d;
        if (a <= 0) {
            cout << "No" << endl;
            return 0;
        }
    }
}