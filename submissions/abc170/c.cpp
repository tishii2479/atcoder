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
    int x, n;
    cin >> x >> n;
    int p;
    set<int> S;
    for (int i = -1; i <= 101; i++) {
        S.insert(i);
    }
    rep(i, n) {
        cin >> p;
        S.erase(p);
    }
    int min = 1000;
    int ans;
    for (int i = 101; i >= -1; i--) {
        if (S.find(i) != S.end()) {
            if (abs(i - x) <= min) {
                min = abs(i - x);
                ans = i;
            }
        }
    }
    cout << ans << endl;
}