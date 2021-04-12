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
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());
    ll ans = a[0];
    int idx = 1;
    for (int i = 2; i < n; i++) {
        ans += a[idx];
        if (i % 2 == 1)
            idx++;
    }
    cout << ans << endl;
}