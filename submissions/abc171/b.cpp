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
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i, n) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    int ans = 0;
    rep(i, k)
        ans += p[i];
    cout << ans << endl;
}