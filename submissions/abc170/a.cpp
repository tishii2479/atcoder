#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
#define MOD 1000000007
// #define MOD 998244353
const ll INF = 1ll << 60;
const int inf = 1 << 29;
int main() {
    int a;
    rep(i, 5) {
        cin >> a;
        if (a == 0) {
            cout << i + 1 << endl;
        }
    }
}