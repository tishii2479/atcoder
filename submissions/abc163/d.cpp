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
#define rep(i, n) for (int i = 0; i < n; i++)
#define repd(i, n) for (int i = n - 1; i >= 0; i--)
#define MOD 1000000007
// #define MOD 998244353
const Int INF = 1LL << 60;
const int inf = 1 << 29;
int main() {
    Int sum = 0;
    int n, k;
    cin >> n >> k;
    Int low = 0;
    Int high = 0;
    for (int i = 1; i <= n + 1; i++) {
        low += i - 1;
        high += n - i + 1;
        if (i >= k) {
            sum += (high - low + 1);
            sum %= MOD;
        }
    }
    cout << sum << endl;
}