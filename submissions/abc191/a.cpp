#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int v, t, s, d;
    cin >> v >> t >> s >> d;
    int l = v * t;
    int r = v * s;
    if (d < l or r < d) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}