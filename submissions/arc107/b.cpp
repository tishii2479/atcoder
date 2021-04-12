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
Int f(Int i, Int n) {
    return min(i, n * 2 + 1 - i);
}
int main() {
    Int N, K;
    cin >> N >> K;
    if (K < 0)
        K = -K;
    vector<Int> num(N * 2 + 1, 0);
    for (Int n = 2; n <= N * 2; ++n)
        num[n] = min(n - 1, N * 2 + 1 - n);
    Int res = 0;
    for (Int n = K; n <= N * 2; ++n)
        res += num[n] * num[n - K];
    cout << res << endl;
}