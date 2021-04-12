#include <algorithm>
#include <cmath>
#include <iostream>
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
    Int s, p;
    cin >> s >> p;
    Int j;
    for (Int i = 1; i * i <= p; i++) {
        if (p % i != 0)
            continue;
        j = p / i;
        if (i + j == s) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}