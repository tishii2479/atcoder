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
    int n, x;
    cin >> n >> x;
    char c;
    rep(i, n) {
        cin >> c;
        if (c == 'o') {
            x++;
        } else {
            if (x > 0)
                x--;
        }
    }
    cout << x << endl;
}