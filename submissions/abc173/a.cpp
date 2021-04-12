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
    int n;
    cin >> n;
    if (1000 - (n % 1000) < 1000) {
        cout << 1000 - (n % 1000) << endl;
    } else {
        cout << 0 << endl;
    }
}