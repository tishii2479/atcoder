#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define MOD 1000000007
// #define MOD 998244353
const ll INF = 1ll << 60;
const int inf = 1 << 29;
int main() {
    int k;
    int a[1000001];
    cin >> k;
    a[1] = 7 % k;
    for (int i = 2; i <= k; i++)
        a[i] = (a[i - 1] * 10 + 7) % k;
    for (int i = 1; i <= k; i++)
        if (a[i] == 0) {
            cout << i << endl;
            return 0;
        }
    cout << -1 << endl;
}