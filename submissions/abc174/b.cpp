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
    ll d;
    cin >> d;
    int count = 0;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        if (x * x + y * y <= d * d) {
            count++;
        }
    }
    cout << count << endl;
}