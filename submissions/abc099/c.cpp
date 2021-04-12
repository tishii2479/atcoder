#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n;
    cin >> n;
    int res = n;
    for (int i = 0; i <= n; i++) {
        int cc = 0;
        int t = i;
        while (t > 0) {
            cc += t % 6;
            t /= 6;
        }
        t = n - i;
        while (t > 0) {
            cc += t % 9;
            t /= 9;
        }
        res = min(cc, res);
    }
    cout << res << endl;
}