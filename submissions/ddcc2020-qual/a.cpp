#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int x, y;
    cin >> x >> y;
    int ans = 0;
    ans += 100000 * max(0, (4 - x));
    ans += 100000 * max(0, (4 - y));
    if (x == 1 and y == 1)
        ans += 400000;
    cout << ans << endl;
}