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
    string s;
    cin >> s;
    int rc = 0;
    int wc = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            rc++;
        }
    }
    int ans = inf;
    for (int i = 0; i < n; i++) {
        ans = min(max(rc, wc), ans);
        if (s[i] == 'R') {
            rc--;
        } else {
            wc++;
        }
    }
    ans = min(max(rc, wc), ans);
    cout << ans << endl;
}